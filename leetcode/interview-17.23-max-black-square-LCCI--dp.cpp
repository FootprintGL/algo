

class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& matrix) {
        /*
         * 动态规划
         * dp[i][j][0/1] - 以(i,j)，0->向右，1->向下
         * 要返回左上角坐标和size，可以从右下向左上更新
         * 如果matrix[i][j] == 1, dp[i][j][0] = dp[i][j][1] = 0
         * 如果matrix[i][j] == 0, dp[i][j][0] = dp[i][j + 1][0] + 1, dp[i][j][1] = dp[i + 1][j] + 1
         * 为了边界好处理，在末尾加一行，右边加一列
         * 一边计算计算边更新结果
         */
        vector<int> ans(3, 0);
        int m = matrix.size();
        if (m == 0)
            return {};

        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(m + 1, vector<int>(2, 0)));
        int i, j;

        for (i = m - 1; i >= 0; i--) {
            for (j = m - 1; j >= 0; j--) {
                if (matrix[i][j] == 0) {
                    /* 黑色 */
                    dp[i][j][0] = dp[i][j + 1][0] + 1;
                    dp[i][j][1] = dp[i + 1][j][1] + 1;
                    int len = min(dp[i][j][0], dp[i][j][1]);

                    while (len >= ans[2]) {
                        if (dp[i + len - 1][j][0] >= len && dp[i][j + len - 1][1] >= len) {
                            ans = {i, j, len};
                            break;
                        }
                        len--;
                    }
                } else {
                    /* 白色 */
                    dp[i][j][0] = dp[i][j][1] = 0;
                }
            }
        }

        if (ans[2] == 0)
            return {};
        else
            return ans;
    }
};
