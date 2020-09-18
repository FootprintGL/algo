

class Solution {
public:
    int titleToNumber(string s) {
        /* 26进制 */
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            /* 先减去A防止整数溢出 */
            ans = ans * 26 - 'A' + s[i]  + 1;
        }

        return ans;
    }
};
