class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp (m + 1, vector<bool>(n + 1, false));
        int i, j;

        /*
         * 动态规划
         * 定义一个(m + 1 * n + 1)的矩阵dp[i][j]表示s的前i个字符和p的前j个字符是否匹配
         * 如果p[j - 1]为字母，则当p[j - 1]和s[i - 1]相等时才能匹配，dp[i][j] = dp[i - 1][j - 1]
         * 如果p[j - 1]为?, 则s[i - 1]为任意字符都可以匹配，dp[i][j] = dp[i - 1][j - 1]
         * 如果p[j - 1]为*, 则*可以匹配空字符或当前字符
         *     *匹配空字符时，dp[i][j] = dp[i][j - 1]
         *     *匹配当前字符时，dp[i][j] = dp[i - 1][j]
         * 边界条件
         * 空串可以相互匹配dp[0][0] = True
         * dp[0][j]: 1 -> n，如果p[j]为*, 则dp[0][j]为True，一旦p[j]不为*,从这里到最后的n，dp[0][j]都为False
         * dp[i][0] = False -> 空pattern无法任何字符串
         */
        dp[0][0] = 1;
        for (j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = true;
                continue;
            }
            break;
        }
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }

        return dp[m][n];
    }
};
