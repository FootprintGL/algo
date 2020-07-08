class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, 0));
        int i, j;

        /*
         * 动态规划
         * 定义一个dp[m + 1][n + 1]的dp数组, dp[i][j]表示p的前j个字符和s的前i个字符是否匹配
         * 如果p[j - 1]等于s[i - 1]或者p[j - 1]等于'.', 该位置匹配，dp[i][j] = dp[i - 1][j - 1]
         * 如果p[j - 1]为'*', 则'p[j - 2]*'可以匹配0个p[j - 2]或多个p[j - 2]
         *     匹配0个p[j - 2]时, dp[i][j] = dp[i][j - 2]
         *     匹配1个p[j - 2]时，如果p[j - 2]等于s[i - 1],则dp[i][j] = dp[i - 1][j]
         * 注意: 对于下标相减需要判断下标越界的情况
         * dp[0][0] = true -> 空模式可以匹配空字符
         * 第0列: dp[i][0] = 0 -> 空模式无法匹配字符
         * 第0行: dp[0][j] -> '*'可以消除前面一个元素，如果奇数位置为'*',可以消除前面字符匹配空串
         * 一旦有一个奇数位置不为’*’,则从该位置到最后都不能匹配空串
         */
        dp[0][0] = true;
        for (i = 0; i < m; i++) {
            dp[i + 1][0] = false;
        }
        for (i = 0; i < n; i++) {
            if (!(i % 2))
                continue;
            if (i % 2 && p[i] == '*') {
                dp[0][i + 1] = true;
                continue;
            }
            break;
        }
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    if (j - 2 >= 0 && (p[j - 2] == s[i - 1] || p[j - 2] == '.')) {
                        dp[i][j] = dp[i - 1][j];
                    }
                    if (j - 2 >= 0) {
                        dp[i][j] = dp[i][j] || dp[i][j - 2];
                    }
                }
            }
        }

        return dp[m][n];
    }
};
