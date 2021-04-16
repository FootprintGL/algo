

class CombinationIterator {
public:
    /*
     * abcd, combinationlength = 2
     * ab - 1100
     * ac - 1010
     * ad - 1001
     * bc - 0110
     * bd - 0101
     * cd - 0011
     * 不需要求出全排列,依次按照二进制编码从大到小的顺序，依次输出字符串即可
     */
    string key;
    int len;
    int curr;

    int countone(int n) {
        int count = 0;
        while (n != 0) {
            count++;
            n &= n - 1;
        }
        return count;
    }

    CombinationIterator(string characters, int combinationLength) {
        key = characters;
        /* 方便映射 - abcd -> dcba - 位遍历从右往左遍历 */
        reverse(key.begin(), key.end());
        len = combinationLength;
        curr = (1 << key.size()) - 1;
        //cout << key << " " << curr << " " << len << endl;
    }

    string next() {
        while (curr >= 0 && countone(curr) != len)
            curr--;
        //cout << curr << endl;
        string res;
        for (int i = 0; i < key.size(); i++) {
            if (curr & (1 << i)) {
                //cout << i << " " << key[i] << " " << endl;
                res = key[i] + res;
            }
        }
        curr--;

        return res;
    }

    bool hasNext() {
        while (curr >= 0 && countone(curr) != len)
            curr--;

        if (curr < 0)
            return false;

        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
