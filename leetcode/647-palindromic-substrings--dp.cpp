
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        if (len == 0)
            return 0;

        /* 
         * 动态规划
         * dp[i][j] - 从i到j的字串是否是回文串
         * 1. 单个字母为回文串
         * 2. 如果两个字母相等为回文串
         * 3. 回文串去掉首位字符还是回文串
         * dp[i][j] = true, 如果s[i] == s[j] && dp[i + 1][j - 1] == true
         * dp[i][i + 1] = true 如果s[i] == s[i - 1]
         * 边界条件dp[i][i] = true
         * 边计算边统计结果
         */
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        int ans = len;
        int i, j;

        /* 单个字母为回文串 */
        for (i = 0; i < len; i++) {
            dp[i][i] = true;
        }

        /* 从下向上遍历 */
        for (i = len - 1; i >= 0; i--) {
            for (j = i + 1; j < len; j++) {
                if (s[i] == s[j]) {
                    if (j - i == 1)
                        /* 2个字母相等为回文串 */
                        dp[i][j] = true;
                    else
                        /* 回文串去掉首位字符还是回文串 */
                        dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = false;
                }
                if (dp[i][j])
                    ans++;
            }
        }

        return ans;
    }
};


class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        if (len == 0)
            return 0;

        /*
         * 动态规划
         * dp[i][j] - 从i到j的字串是否是回文串
         * 1. 单个字母为回文串
         * 2. 如果两个字母相等为回文串
         * 3. 回文串去掉首位字符还是回文串
         * dp[i][j] = true, 如果s[i] == s[j] && dp[i + 1][j - 1] == true
         * dp[i][i + 1] = true 如果s[i] == s[i - 1]
         * 边界条件dp[i][i] = true
         * 边计算边统计结果
         */
        vector<vector<int>> dp(len, vector<int>(len, false));
        int ans = 0;
        int i, j, k;

        /* 单个字母为回文串 */
        for (i = 0; i < len; i++) {
            dp[i][i] = true;
        }
        ans += len;

	/* 从上向下斜着遍历 */
        for (j = 2; j <= len; j++) {
            for (i = len - j; i >= 0; i--) {
                if (j == 2) {
                    /* 如果两个字母相等为回文串 */
                    if (s[i] == s[i + j - 1]) {
                        dp[i][i + j - 1] = true;
                        ans++;
                    }
                } else {
                    /* 回文串去掉首位字符还是回文串 */
                    if (s[i] == s[i + j - 1] && dp[i + 1][i + j - 2]) {
                        dp[i][i + j - 1] = true;
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
