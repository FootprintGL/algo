


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int nc = coins.size();
        int i, j;

        /*
         * 动态规划
         * dp[i] - 凑出金额i最少需要几块硬币
         * dp[i] = min(dp[i - coins[j]]) + 1, j: 0 -> coins.size() - 1
         * dp[amount]即为结果
         */
        dp[0] = 0;
        for (i = 1; i <= amount; i++) {
            for (j = 0; j < nc; j++) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != -1) {
                    if (dp[i] == -1)
                        dp[i] = dp[i - coins[j]] + 1;
                    else
                        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount];
    }
};
