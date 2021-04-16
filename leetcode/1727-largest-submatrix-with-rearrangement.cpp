

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        /*
         * 统计每个位置上面连续1的个数，降成一维
         * 每行排序，枚举行更新最大矩阵面积
         */
        int m = matrix.size();
        int n = matrix[0].size();
        /* 统计每个位置上面连续1的个数 */
        vector<vector<int>> dp(m, vector<int>(n, 0));

        /* 统计每个位置上面连续1的个数，包含(i, j)位置 */
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    dp[i][j] = 1;
                    if (i > 0)
                        dp[i][j] += dp[i - 1][j];
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        /* 排序，计算并统计最大矩形面积 */
        int area = 0;
        for (int i = 0; i < m; i++) {
            sort(dp[i].begin(), dp[i].end());
            for (int j = 0; j < n; j++) {
                //cout << dp[i][j] << " " << (n - j) << endl;
                area = max(area, dp[i][j] * (n - j));
            }
        }

        return area;
    }
};
