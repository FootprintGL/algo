class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        int i, j;

        if (m + n != s3.size())
            return false;

        /*
         * 动态规划
         * dp[i][j]表示s1前i个字符和s2的前j个字符可以交错组成s3的前i + j个字符
         * 如果s1[i - 1] == s3[i + j - 1], 则dp[i][j]取决于dp[i - 1][j]
         * 如果s2[j - 1] == s3[i + j - 1], 则dp[i][j]取决于dp[i][j - 1]
         * 返回dp[m][n]
         */
        dp[0][0] = 1;
        for (i = 0; i <= m; i++) {
            for (j = 0; j <= n; j++) {
                if (i > 0)
                    dp[i][j] |= dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
                if (j > 0)
                    dp[i][j] |= dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[m][n];
    }
};
