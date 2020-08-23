

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        /*
         * 动态规划
         * dp[i][j] - 从i到j的字串最长回文子序列的长度
         * 如果s[i] == s[j]，dp[i][j] = dp[i + 1][j - 1] + 2
         * 如果s[i] != s[j], s[i]或s[j]不同时在最长回文子序列中，dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
         * 结果为dp[0][n - 1]
         */
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int i, j;

        /* 单个字符为回文串，长度为1 */
        for (i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        /* 从下向上计算更新 */
        for (i = n - 1; i >= 0; i--) {
            for (j = i + 1; j < n; j++) {
                //cout << i << " " << j << " ";
                if (s[i] == s[j]) {
                    //cout << "==" << endl;
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else {
                    //cout << "!=" << endl;
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }

        return dp[0][n - 1];
    }
};
