
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {

        /*
         * 动态规划
         * dp[i][j][0] - (i, j)向左连续1的个数，dp[i][j][1] - (i,j)向上连续1的个数
         * 如果grid[i][j] == 0, dp[i][j][k] = 0
         * 如果grid[i][j] == 1, dp[i][j][0] = dp[i][j - 1][0] + 1, dp[i][j][1] = dp[i - 1][j][1] + 1
         * 边计算边更新最大正方形边长ans
         */
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>> (n + 1, vector<int> (2, 0)));
        int i, j;

        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                if (grid[i - 1][j - 1]) {
                    dp[i][j][0] = dp[i][j - 1][0] + 1;
                    dp[i][j][1] = dp[i - 1][j][1] + 1;
                } else {
                    dp[i][j][0] = dp[i][j][1] = 0;
                }
                int len = min(dp[i][j][0], dp[i][j][1]);
                while (len > ans) {
                    if (dp[i][j - len + 1][1] >= len && dp[i - len + 1][j][0] >= len) {
                        /* 找到更大正方形网络 */
                        ans = len;
                        break;
                    }
                    len--;
                }
            }
        }

        return ans * ans;
    }
};
