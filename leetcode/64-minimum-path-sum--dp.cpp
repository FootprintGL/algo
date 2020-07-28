

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int i, j;
        int sum = 0;
        /*
         * 动态规划
         * dp[i][j] = min(dp[i - 1][j], dp[i][j - 1])
         */
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
            for(j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};
