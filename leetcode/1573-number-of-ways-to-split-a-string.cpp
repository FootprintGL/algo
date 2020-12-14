


class Solution {
public:
    int numWays(string s) {
        /* long防止整数overflow */
        int res = 0;
        long n = s.length();
        long cnt = 0;
        unordered_map<long, long> idx;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cnt++;
                idx[cnt] = i;
            }
        }

        if (cnt % 3)
        /* 1的个数不能被3整除 */
            return 0;

        if (cnt == 0)
        /* 全0 - 有cnt - 1个间隔，随意切割成3段 */
            return (n - 1) * (n - 2) / 2 % mod;

        /* 每段有cnt / 3个1，计算 */
        long pos = cnt / 3;
        return (idx[pos + 1] - idx[pos]) * (idx[2 * pos + 1] - idx[2 * pos]) % mod;
    }
};
