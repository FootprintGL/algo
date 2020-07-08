class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int i, j;
        /*
         * 动态规划
         * dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
         * dp[0][j] -> 只要obstacleGrid[0][j]为1，则从j开始到最后都无法到达 
         * dp[i][0] -> 只要obstacleGrid[i][0]为1，则从i开始到最后都无法到达 
         * 注意障碍物处无法到达，dp为0
         * 结果为dp[m - 1][n - 1]
         */
        for (i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = 1;
                continue;
            }
            break;
        }
        for (i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 0) {
                dp[0][i] = 1;
                continue;
            }
            break;
        }
        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};
