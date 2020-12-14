

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        /*
         * 寻找到终止长度为b + 2 * a
         * b的可能组成为: a的后面部分 + 若干个a + a的前面部分
         * a'{a''[a...a]a'}a'' - {}里为b
         */
        int ret = 1;
        int na = a.size(), nb = b.size();
        string temp = a;

        while(temp.size() < nb + 2 * na) {
            if (temp.find(b) != temp.npos)
                return ret;
            temp += a;
            ret++;
        }

        return -1;
    }
};
