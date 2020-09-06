

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        /*
         * 动态规划
         * dp[i][j] - 剩下nums[i -> j]时玩家1可以比玩家2多拿多少分
         * (j - i + 1) % 2和flag相同，轮到玩家1拿，
         * dp[i][j] = max{dp[i + 1][j] + nums[i], dp[i][j - 1] + nums[j]}
         * (j - i + 1) % 2和flag不同轮到玩家2拿
         * dp[i][j] = min{dp[i + 1][j] - nums[i], dp[i][j - 1] - nums[j]}
         * 结果为dp[0][n - 1] >= 0
         * dp[i][i] = nums[i] -> 奇数堆
         * dp[i][i] = -nums[i] -> 偶数堆
         */
        int n = nums.size();
        int flag = n % 2;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int i, j;

        /* 只剩1堆 */
        for (i = 0; i < n; i++)
            dp[i][i] = nums[i] * (flag ? 1 : -1);

        for (i = n - 2; i >= 0; i--) {
            for (j = i + 1; j < n; j++) {
                if ((j - i + 1) % 2 == flag) {
                    dp[i][j] = max(dp[i + 1][j] + nums[i], dp[i][j - 1] + nums[j]);
                } else {
                    dp[i][j] = min(dp[i + 1][j] - nums[i], dp[i][j - 1] - nums[j]);
                }
            }
        }

        return dp[0][n - 1] >= 0;
    }
};
