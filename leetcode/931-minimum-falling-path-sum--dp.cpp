class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        /*
         * 动态规划
         * dp[i][j] - 下降到(i,j)路径最小和
         * dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i - 1][j + 1]) + A[i][j]
         * 方便边界处理，左右各多加一列，注意j的偏移
         *  1. A[i][j] -> [-100, 100]且是求最小值，多加的2列设为101
         *  2. 第一行设为A的第一行
         * 结果为最后一行的最小值
         */
        int m = A.size(), n = A[0].size();
        vector<vector<int>> dp(m, vector<int> (n + 2, 101));
        int i, j;
/*
        for (i = 0; i < m; i++) {
            for (j = 0; j < n + 2; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
        cout << endl;
*/
        /* 初始化第一行 */
        for (j = 1; j <= n; j++) 
            dp[0][j] = A[0][j - 1];

        /* 更新dp表格 */
        for (int i = 1; i < m; i++) {
            for (j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i - 1][j + 1])) + A[i][j - 1];
            }
        }

        /* 结果最后一行的最小值 */
        int ans = dp[m - 1][1];
        for (j = 2; j <= n; j++) {
            if (ans > dp[m - 1][j])
                ans = dp[m - 1][j];
        }

        return ans;
    }
};
