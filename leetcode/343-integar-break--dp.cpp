


class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        int i, j;

        /*
         * 动态规划
         * dp[i] - i拆分的最大乘积
         * dp[i] = max(j * (i - j), j * dp[i - j]) j: 1 -> i
         * dp[0] = dp[1] = 0
         * 结果为dp[n]
         */
        dp[0] = dp[1] = 0;
        for (i = 2; i <= n; i++) {
            for (j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }

        return dp[n];
    }
};
