
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        /*
         * 动态规划
         * dp[i][j] - text1的前i个字符和text2的前j个字符最长公共子序列的长度
         * 如果text1[i] == text[j], dp[i][j] = dp[i - 1][j - 1] + 1
         * 如果text1[i] != text[j], dp[i][j] = max{dp[i - 1][j], dp[i][j - 1]}
         * 边界条件: 第一列: 如果text1[k] == text2[0], 从k开始到最后, dp[k][0] = 1
         *          第一行: 如果text1[0] == text2[k], 从k开始到最后, dp[0][k] = 1
         * 结果为dp[m][n]
         */
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int ans = 0;
        int i, j;

        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
/*
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
*/
        return dp[m][n];
    }
};



class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        /*
         * 动态规划
         * dp[i][j] - text1的前i个字符和text2的前j个字符最长公共子序列的长度
         * 如果text1[i] == text[j], dp[i][j] = dp[i - 1][j - 1] + 1
         * 如果text1[i] != text[j], dp[i][j] = max{dp[i - 1][j], dp[i][j - 1]}
         * 边界条件: 第一列: 如果text1[k] == text2[0], 从k开始到最后, dp[k][0] = 1
         *          第一行: 如果text1[0] == text2[k], 从k开始到最后, dp[0][k] = 1
         * 结果为dp[m - 1][n - 1]
         */
        int m = text1.size(), n = text2.size();
        if (m == 0 || n == 0)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int tmp, ans = 0;
        int i, j;

        /* 第一行 */
        tmp = 0;
        for (j = 0; j < n; j++) {
            if (text1[0] == text2[j])
                tmp = 1;
            dp[0][j] = tmp;
        }

        /* 第一列 */
        tmp = 0;
        for (i = 0; i < m; i++) {
            if (text1[i] == text2[0])
                tmp = 1;
            dp[i][0] = tmp;
        }

        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++) {
                if (text1[i] == text2[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
/*
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
*/
        return dp[m - 1][n - 1];
    }
};
