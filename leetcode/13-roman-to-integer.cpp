

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> tbl = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        /* 如果当前的数字小于右边的数字，则减去该值，否则加上该值 */
        int ans = 0, i;
        for (i = 0; i < s.length() - 1; i++) {
            if (tbl[s[i]] < tbl[s[i + 1]])
                ans -= tbl[s[i]];
            else
                ans += tbl[s[i]];
        }
        ans += tbl[s[i]];

        return ans;
    }
};
