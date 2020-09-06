

class Solution {
public:

    int minimumDeleteSum(string s1, string s2) {
        /*
         * dp[i][j] - s1的前i个字符和s2的前j个字符相等需要删除字符的ASCII值的最小和
         * 如果s1[i] == s2[j], dp[i][j] = dp[i - 1][j - 1]
         * 如果s1[i] != s2[j], dp[i][j] = min(dp[i - 1][j] + ascii(s1[i]), dp[i][j - 1] + ascii(s2[j]))
         * dp[0][j] = dp[0][j - 1] + s2[j]
         * dp[i][0] = dp[i][0] + s1[i]
         * 结果为dp[m][n]
         */
        int m = s1.length(), n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        int i, j;

        for (i = 1; i <= m; i++)
            dp[i][0] = dp[i - 1][0] + s1[i - 1];

        for (j = 1; j <= n; j++)
            dp[0][j] = dp[0][j - 1] + s2[j - 1];

        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                }
            }
        }

/*
        cout << m << " " << n << endl;
        for (i = 0; i <= m; i++) {
            for (j = 0; j <= n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
*/
        return dp[m][n];
    }
};
