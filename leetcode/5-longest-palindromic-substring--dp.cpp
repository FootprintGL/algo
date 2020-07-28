

class Solution {
public:
    vector<bool> dp;
    string longestPalindrome(string s) {
        int len = s.length();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        int start = 0, end = 0;
        int i, j, l;

        /*
         * 动态规划
         * dp[i][j]表示s[i] - s[j]的字串是否是回文串
         * i-j大于2个元素，如果i-j元素是回文串，则去掉首位元素仍然是回文串
         * dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j]
         * 两个元素相等时为回文串，单个字符是回文串
         * dp[i][i] = 1, dp[i][i + 1] = s[i] == s[i + 1]
         * 注意: 字串从短到长计算
         */
        for (l = 1; l <= len; l++) {
            for (i = 0; i < len - l + 1; i++) {
                j = i + l - 1;
                if (l == 1)
                    dp[i][j] = true;
                else if (l == 2)
                    dp[i][j] = s[i] == s[j];
                else
                    dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];

                if (dp[i][j] && (j - i) > (end - start)) {
                    start = i;
                    end = j;
                }
            }
        }

        return s.substr(start, end - start + 1);
    }
};



class Solution {
public:
    vector<bool> dp;
    string longestPalindrome(string s) {
        int len = s.length();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        int start = 0, end = 0;
        int i, j, l;

        /*
         * 动态规划
         * dp[i][j]表示s[i] - s[j]的字串是否是回文串
         * i-j大于2个元素，如果i-j元素是回文串，则去掉首位元素仍然是回文串
         * dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j]
         * 两个元素相等时为回文串，单个字符是回文串
         * dp[i][i] = 1, dp[i][i + 1] = s[i] == s[i + 1]
         */
        /* 边界条件 */
        for (i = 0; i < len; i++) {
            dp[i][i] = true;
            if (i + 1 < len) {
                dp[i][i + 1] = (s[i] == s[i + 1]);
                if (dp[i][i + 1]) {
                    start = i;
                    end = i + 1;
                }
            }
        }
        /* 字串从短到长计算 */
        for (l = 3; l <= len; l++) {
            for (i = 0; i < len - l + 1; i++) {
                j = i + l - 1;
                dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                if (dp[i][j] && (j - i) > (end - start)) {
                    start = i;
                    end = j;
                }
            }
        }

        return s.substr(start, end - start + 1);
    }
};
