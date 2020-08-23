

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        if (n == 0)
            return 0;

        /*
         * 动态规划
         * dp[i][j] - 表示以(i,j)为右下角的正方形的最长边长
         * dp[i][j] = min{dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}, 如果matrix[i][j] == 1
         * dp[i][j] = 0, 如果matrix[i][j] == 0
         * 边界条件: dp[i][j] = matrix[i][j], 如果i == 0 或 j == 0
         * 边计算边更新结果
         */
        vector<vector<int>> dp (m, vector<int> (n, 0));
        int res = 0;
        int i, j;

        for (i = 0; i < m; i++) {
            if (matrix[i][0] == '1') {
                dp[i][0] = matrix[i][0] - '0';
                res = 1;
            }
        }

        for (j = 0; j < n; j++) {
            if (matrix[0][j] == '1') {
                dp[0][j] = matrix[0][j] - '0';
                res = 1;
            }
        }

        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                    dp[i][j]++;
                    if (res < dp[i][j])
                        res = dp[i][j];
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return res * res;
    }
};
