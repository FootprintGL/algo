

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        /*
         * 动态规划
         * dp[i][j] - 前i个骰子拼成j的组合数
         * dp[i][j] = sum(dp[i - 1][j - k), k = 1 -> f
         * dp[1][k] = 1, k: 1 -> min(f, target)
         * 结果为dp[d][target]
         */
        vector<vector<int>> dp(d + 1, vector<int> (target + 1, 0));
        int M = 1000000007;
        int i, j, k;

        if (d * f < target || target < d)
            return 0;

        for (i = 1; i <= min(target, f); i++)
            dp[1][i] = 1;

        for (i = 2; i <= d; i++) {
            for (j = i; j <= target; j++) {
                for (k = 1; j - k >= 0 && k <= f; k++) {
                    if (j - k >= 0)
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % M;
                }
            }
        }

/*
        for (i = 0; i <= d; i++) {
            for (j = 0; j <= target; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
*/
        return dp[d][target];
    }
};
