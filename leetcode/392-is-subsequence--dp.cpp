

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ns = s.size(), nt = t.size();
        vector<vector<bool>> dp(ns + 1, vector<bool>(nt + 1, false));
        int i, j;

        /*
         * 动态规划
         * dp[i][j] = (dp[i - 1][j - 1] && s[i] == s[j]) || (dp[i][j - 1])
         * dp[i][0] = false
         * dp[0][j] = true
         */
        dp[0][0] = true;
        for (i = 1; i <= ns; i++)
            dp[i][0] = false;
        for (j = 1; j <= nt; j++)
            dp[0][j] = true;
        for (i = 1; i <= ns; i++) {
            for (j = 1; j <= nt; j++) {
                dp[i][j] = (dp[i - 1][j - 1] && s[i - 1] == t[j - 1]) || (dp[i][j - 1]);
                //cout << i << "-" << j << ":" << dp[i][j] << endl;
            }
        }

        return dp[ns][nt];
    }
};


class Solution {
public:

    bool isSubsequence(string s, string t) {
        int ns = s.size(), nt = t.size();
        int find = 0;
        int i, j, k = 0;

        /* 暴力循环 */
        for (i = 0; i < ns; i++) {
            for (j = k; j < nt; j++) {
                if (s[i] == t[j]) {
                    k = j + 1;
                    find++;
                    break;
                }
            }
        }

        return find == ns;
    }
};
