
class Solution {
public:
    int waysToChange(int n) {
        /*
         * 动态规划
         * dp[i][j] - 前i个面值构成j的方案数
         * dp[i][j] = dp[i - 1][j] + dp[i - 1][j - coins[i]] + ... + dp[i - 1][j - k * coins[i]] k = j / coins[i]
         * 令j = j - coins[i]
         * dp[i][j - coins[i]] = dp[i - 1][j - ci] + ... + dp[i -  1][k * coins[i]] + dp[i - 1][j - (k + 1) * coins[i]]
         * j - (k + 1) * coins[i] < 0, dp[i - 1][j - (k + 1) * coins[i]] == 0
         * 两式相减得dp[i][j] - dp[i][j - coins[i]] = dp[i - 1][j]
         * dp[i][j] = dp[i][j - coins[i]] + dp[i - 1][j]
         * dp[i][j]只和当前行和上一行有关，可以用滚动数组降到一维dp[j] = dp[j] + dp[j - coins[i]], 如果j >= coins[i]
         * 结果为dp[4][n]
         */
        int coins[4] = {1, 5, 10, 25};
        int M = 1000000007;
        vector<int> dp(n + 1, 0);
        int i, j;

        dp[0] = 1;
        for (i = 0; i < 4; i++) {
            for (j = coins[i]; j <= n; j++) {
                dp[j] = (dp[j] + dp[j - coins[i]]) % M;
            }
        }

        return dp[n];
    }
};


class Solution {
public:
    int waysToChange(int n) {
        /*
         * 动态规划
         * dp[i][j] - 前i个面值构成j的方案数
         * dp[i][j] = dp[i - 1][j] + dp[i - 1][j - coins[i]] + ... + dp[i - 1][j - k * coins[i]] k = j / coins[i]
         * 令j = j - coins[i]
         * dp[i][j - coins[i]] = dp[i - 1][j - ci] + ... + dp[i -  1][k * coins[i]] + dp[i - 1][j - (k + 1) * coins[i]]
         * j - (k + 1) * coins[i] < 0, dp[i - 1][j - (k + 1) * coins[i]] == 0
         * 两式相减得dp[i][j] - dp[i][j - coins[i]] = dp[i - 1][j]
         * dp[i][j] = dp[i][j - coins[i]] + dp[i - 1][j]
         * dp[i][j]只和当前行和上一行有关，可以用滚动数组降到一维
         * 结果为dp[4][n]
         */
        int coins[4] = {1, 5, 10, 25};
        int M = 1000000007;
        vector<int> dp(n + 1, 0);
        int i, j;

        dp[0] = 1;
        for (i = 0; i < 4; i++) {
            for (j = 1; j <= n; j++) {
                if (j >= coins[i])
                    dp[j] = (dp[j] + dp[j - coins[i]]) % M;
            }
        }

        return dp[n];
    }
};



class Solution {
public:
    int waysToChange(int n) {
        /*
         * 动态规划
         * dp[i][j] - 前i个面值构成j的方案数
         * dp[i][j] = dp[i - 1][j] + dp[i - 1][j - coins[i]] + ... + dp[i - 1][j - k * coins[i]] k = j / coins[i]
         * 令j = j - coins[i]
         * dp[i][j - coins[i]] = dp[i - 1][j - ci] + ... + dp[i -  1][k * coins[i]] + dp[i - 1][j - (k + 1) * coins[i]]
         * j - (k + 1) * coins[i] < 0, dp[i - 1][j - (k + 1) * coins[i]] == 0
         * 两式相减得dp[i][j] - dp[i][j - coins[i]] = dp[i - 1][j]
         * dp[i][j] = dp[i][j - coins[i]] + dp[i - 1][j]
         * dp[i][j]只和当前行和上一行有关，可以用滚动数组降到一维
         * 结果为dp[4][n]
         */
        int coins[4] = {1, 5, 10, 25};
        int M = 1000000007;
        vector<vector<int>> dp(4 + 1, vector<int>(n + 1, 0));
        int i, j, k;

        dp[0][0] = 1;
        for (i = 1; i <= 4; i++) {
            for (j = 0; j <= n; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1])
                    dp[i][j] = (dp[i][j] + dp[i][j - coins[i - 1]]) % M;
            }
        }
/*
        for (i = 0; i <= 4; i++) {
            for (j = 0; j <= n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
*/
        return dp[4][n];
    }
};

