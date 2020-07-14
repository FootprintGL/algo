
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp (n, vector<int>(2, 0));

        if (n <= 1)
            return 0;

        /*
         * 动态规划
         * dp[i][j]表示第i天能取得的最大利润
         * i -> 第i天
         * j -> 第i天是持有股票还是持有现金，0表示现金，1表示股票
         * dp[i][0] - 持有现金
         * 1. 可能是第i - 1天已经持有现金
        *  2. 可能是第i - 1天持有股票当天卖了
         * dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
         * dp[i][1] - 持有股票
         * 1. 可能是第i - 1天已经持有股票，
         * 2. 可能是第i - 1天持有现金，第i天买了股票。第i - 1天不能卖股票，有两种可能。
         *    1). 第i - 2天持有现金
         *    2). 地i - 2天持有股票，当天卖出
         *    dp[i - 1][0] => max(dp[i - 2][0], dp[i - 2][1] + prices[i - 2])
         * dp[i][1] = max(dp[i - 1][1], max(dp[i - 2][0], dp[i - 2][1] + prices[i - 2]) - prices[i]);
         */
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);
        dp[1][1] = max(dp[0][1], dp[0][0] - prices[1]);

        for (int i = 2; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], max(dp[i - 2][0], dp[i - 2][1] + prices[i - 2]) - prices[i]);
        }

        return dp[n - 1][0];
    }
};

