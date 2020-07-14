class Solution {

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if (m == 0)
            return 1;
        int n = dungeon[0].size();
        if (n == 0)
            return 1;

        int dp[m][n];
        int i, j;

        /*
         * 动态规划
         * 从左上到右下，不能通过所有测试用例，看似最优解，并不是最有接
         * [[1,-3,-3], [0,-2,0],[-3,-3,-3]]
         * 需从右下到左上实行动态规划
         * dp[i][j]表示从(i,j)到右下角需要的健康点数，骑士保持活着状态，最少为-1
         * dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]))
         */
        dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);
        /* 第m - 1行 - 最后一行 */
        for (i = n - 2; i >= 0; i--)
            dp[m - 1][i] = max(1, dp[m - 1][i + 1] - dungeon[m - 1][i]);
        /* 第n - 1列 - 最后一列 */
        for (i = m - 2; i >= 0; i--) {
            dp[i][n - 1] = max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
        }
        for (i = m - 2; i >= 0; i--)
            for (j = n - 2; j >= 0; j--) {
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }

        return dp[0][0];
    }
};
