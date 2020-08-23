
/* 优化： 可直接更新grid减少空间利用 */

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        /*
         * 动态规划
         * dp[i][j] = max{dp[i - 1][j], dp[i][j - 1]} + grid[i][j]
         * i == 0, dp[0][j] = sum{grid[0][j]}
         * j == 0, dp[i][0] = sum{grid[i][0]}
         */
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int i, j, sum = 0;

        for (i = 0; i < m; i++) {
            sum += grid[i][0];
            dp[i][0] = sum;
        }
        sum = 0;
        for (j = 0; j < n; j++) {
            sum += grid[0][j];
            dp[0][j] = sum;
        }

        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++) {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }
/*
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
*/
        return dp[m - 1][n - 1];
    }
};
