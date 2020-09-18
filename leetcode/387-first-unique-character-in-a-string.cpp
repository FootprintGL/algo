

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> tbl;
        int letter[26] = {0}, i;

        /* 找第一个 - 从后向前遍历更新索引 */
        for (i = s.length() - 1; i >= 0; i--) {
            letter[s[i] - 'a'] = i;
            tbl[s[i]]++;
        }
        /* 找单个字符和位置 */
        for (auto &c : s)
            if (tbl[c] == 1)
                return letter[c - 'a'];

        return -1;
    }
};
