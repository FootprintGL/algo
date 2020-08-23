

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        if (n == 0)
            return 0;

        /*
         * 动态规划
         * dp[i][j] - 表示以(i,j)为右下角的正方形的最长边长，以(i, j)为右下角长度为(1, 2, ..., dp[i][j])的正方形各一个
         * dp[i][j] = min{dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}, 如果matrix[i][j] == 1
         * dp[i][j] = 0, 如果matrix[i][j] == 0
         * 边界条件: dp[i][j] = matrix[i][j], 如果i == 0 或 j == 0
         * 边计算边更新结果
         */
        vector<vector<int>> dp (m, vector<int> (n, 0));
        int res = 0;
        int i, j;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if ((i == 0 || j == 0) && matrix[i][j]) {
                    dp[i][j] = matrix[i][j];
                    res++;
                } else {
                    if (matrix[i][j] == 1) {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                        res += dp[i][j];
                    } else {
                        dp[i][j] = 0;
                    }
                }
            }
        }

        return res;
    }
};
