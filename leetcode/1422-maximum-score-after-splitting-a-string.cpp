

class Solution {
public:
    int maxScore(string s) {
        int cnt1 = 0;
        int res = 0;

        /* 统计1的个数 */
        for (auto c : s)
            if (c == '1')
                cnt1++;

        int c0 = 0, c1 = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '0')
                c0++;
            else
                c1++;

            /* 左边有c0个0，右边有cnt1 - c1个1 */
            if (c0 + cnt1 - c1 > res)
                res = c0 + cnt1 - c1;
        }

        return res;
    }
};
