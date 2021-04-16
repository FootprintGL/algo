

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /*
         * 动态规划
         * dp[i] - 凑成总金额i的组合数
         * 依次添加每种面值硬币并更新组合数dp[i] = dp[i] + dp[i - coin]
         * dp[0] = 1 - 总金额为0有一种组合方法，所有面值银币为0
         */
        int n = coins.size();
        vector<int> dp(amount + 1, 0);

        dp[0] = 1;
        for (auto &coin : coins) {
            for (int i = coin; i <= amount; i++)
                dp[i] += dp[i - coin];
        }

        return dp[amount];
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /*
         * 动态规划
         * dp[i][j] - 用前j种硬币凑成总金额i的组合数
         * 前j种硬币凑齐i的组合数 = 前j - 1种硬币凑齐金额i的组合数 + 原来i - k
         * 的基础上使用硬币的组合数
         * 分两种情况
         *      1. 用前j - 1种凑齐
         *      2. 前面凑了i - coins[j], 就差一个coin[j]了
         * dp[i][j] = dp[i][j - 1] + dp[i - coins[j]][j]
         * dp[0][j] = 1
         */
        int n = coins.size();
        vector<vector<int>> dp(amount + 1, vector<int> (n + 1, 0));

        for (int j = 0; j <= n; j++)
            dp[0][j] = 1;

        for (int i = 1; i <= amount; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i][j - 1];
                if (i >= coins[j - 1])
                    dp[i][j] += dp[i - coins[j - 1]][j];
            }
        }
/*
        for (int i = 0; i <= amount; i++) {
            for (int j = 0; j <= n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
*/
        return dp[amount][n];
    }
};
