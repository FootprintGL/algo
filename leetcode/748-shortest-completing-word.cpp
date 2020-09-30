

class Solution {
public:
    /* 处理车牌 - 保留字母并转换为小写 */
    string transformplate(string word) {
        string res;
        for (auto &c : word) {
            if ((c >= 'a' && c <= 'z') || c >= 'A' && c <= 'Z')
                res.push_back(c |= 0x20);
        }
        return res;
    }

    bool contain(unordered_map<char, int> &tbl, string w2) {
        unordered_map<char, int> tmp;

        for (auto &c : w2)
            tmp[c]++;

        for (auto &[c, cnt] : tbl)
            if (tmp.count(c) == 0 || tbl[c] > tmp[c])
                return false;

        return true;
    }

    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string res;
        unordered_map<char, int> tbl;
        int minlen = INT_MAX;

        /* 哈希表 */
        string str = transformplate(licensePlate);
        for (auto &c : str)
            tbl[c]++;

        for (auto &word : words) {
            if (contain(tbl, word)) {
                if (word.length() < minlen) {
                    res = word;
                    minlen = word.length();
                }
            }
        }

        return res;
    }
};
