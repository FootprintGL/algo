

class Solution {
public:
    int numWays(int n) {
        /*
         * 动态规划
         * dp[i] = dp[i - 1] + dp[i - 2]
         * dp[0] = dp[1] = 1;
         * dp[2] = dp[0] + dp[1]
         * 结果为dp[n]
         */
        int M = 1e9 + 7;
        vector<int> dp(n + 1, 1);

        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % M;
        }

        return dp[n];
    }
};
