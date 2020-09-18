

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> tbl;
        int idx[26] = {}, minidx = INT_MAX;

        /* 找第一个 - 从后往前遍历, idx存放每个字母第一次出现的下标，tbl统计每个字母出现的次数 */
        for (int i = s.length() - 1; i >= 0; i--) {
            tbl[s[i]]++;
            idx[s[i] - 'a'] = i;
        }

        for (auto &[c, cnt] : tbl) {
            if (cnt == 1 && idx[c - 'a'] < minidx)
                minidx = idx[c - 'a'];
        }

        return minidx == INT_MAX ? ' ' : s[minidx];
    }
};
