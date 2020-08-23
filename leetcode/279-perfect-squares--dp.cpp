
class Solution {
public:
    int numSquares(int n) {
        /*
         * 动态规划
         * dp[i] - 凑出i最少需要几个完全平方数
         * dp[i] = dp[i - j] + 1, j: 0 -> ...
         * 结果为dp[n]
         */
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= n; j++) {
                if (i - j * j >= 0 && dp[i - j * j] != -1) {
                    if (dp[i] == -1) {
                        dp[i] = dp[i - j * j] + 1;
                    } else {
                        dp[i] = min(dp[i], dp[i - j * j] + 1);
                    }
                }
            }
        }

        return dp[n];
    }
};
