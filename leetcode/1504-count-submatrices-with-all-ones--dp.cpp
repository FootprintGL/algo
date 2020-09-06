
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        /*
         * 动态规划
         * dp[i][j] - (i,j)为右下角的矩形数量
         * dp[i][j] = dp[i - 1][j] + 1, mat[i][j] == 1
         * dp[i][j] = 0, mat[i][j] == 0
         * h[i][j] - (i,j)向上1向上延伸的高度
         * mat[i][j] == 1, 从j列往左，找到第一个比h[i][j]矮的
         * dp[i][j]分成2部分
         * dp[i][j] = (j - p) * h[i][j] + dp[i][p]
         * 边计算dp边统计结果
         */
        int ans = 0;
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> height(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int i, j, p;

        /* 计算高度 */
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                if (mat[i - 1][j - 1] == 1) {
                    height[i][j] = height[i - 1][j] + 1;
                } else {
                    height[i][j] = 0;
                }
            }
        }

        /* 计算dp并更新结果ans */
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                if (mat[i - 1][j - 1] == 1) {
                    p = j - 1;
                    while (p >= 1 && height[i][p] >= height[i][j])
                        p--;
                    //cout << p << endl;
                    dp[i][j] = height[i][j] * (j - p) + dp[i][p];
                    ans += dp[i][j];
                }
            }
        }

        return ans;
    }
};


class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        /*
         * 动态规划
         * (i,j)向左上角的个数，为计算从i行高度为1，2，...，i的个数
         * 往上找时，每一行矩形高度是确定的，宽度为最小宽度
         * dp[i][j] - 记录(i,j)左边1的个数
         * 如果mat[i][j] == 0, dp[i][j] = 0
         * 如果mat[i][j] == 1, dp[i][j] = dp[i][j - 1] + 1
         * 边更新边累计结果ans
         */
        int ans = 0;
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp (m + 1, vector<int> (n + 1, 0));
        int i, j, k;

        /* 统计左边1的个数和高度为1的矩形个数 */
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                if (mat[i - 1][j - 1] == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i][j - 1] + 1;
                    ans += dp[i][j];
                }
            }
        }

        /* 统计并累加高度为2，3，...矩形的个数 */
        for (i = 2; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                if (mat[i - 1][j - 1] == 1) {
                    int wid = dp[i][j];
                    for (k = i - 1; k >= 1; k--) {
                        wid = min(wid, dp[k][j]);
                        ans += wid;
                    }
                }
            }
        }

        return ans;
    }
};
