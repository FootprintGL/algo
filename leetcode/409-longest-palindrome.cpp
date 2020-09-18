

class Solution {
public:
    int longestPalindrome(string s) {
        /* 哈希表 */
        unordered_map<char, int> tbl;
        int res = 0;
        bool oddexist = false;

        for (auto const &c : s)
            tbl[c]++;

        for (auto const &[c, cnt] : tbl) {
            if (cnt % 2) {
                res += cnt - 1;
                oddexist = true;
            } else {
                res += cnt;
            }
        }

        return oddexist ? res + 1 : res;
    }
};
