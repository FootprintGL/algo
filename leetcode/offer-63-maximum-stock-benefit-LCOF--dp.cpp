class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
         * 贪心算法
         * 最低价买最高价卖，记录并维护最低股票价格
         * 计算并更新能获得的最大利润
         */
        int n = prices.size();
        int minprice = INT_MAX, ans = 0;

        if (n < 2)
            return 0;

        for (int i = 0; i < n; i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else
                ans = max(ans, prices[i] - minprice);
        }

        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        /*
         * 动态规划
         * dp[i][0] - 第i天不持有股票能获得的最大利润
         * dp[i][1] - 第i天持有股票能获得的最大利润
         * dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + price[i])
         * dp[i][1] = max(dp[i - 1][1], -price[i])
         * 注意：dp[i][1]不能从dp[i - 1][0]转换过来，因为只能交易一次
         * 实际状态0特指卖出股票不持股的状态，和没有经过任何一次交易的不持有股票状态是有区别的
         * 结果为dp[n][0]
         */
        int n = prices.size();

        if (n < 2)
            return 0;

        vector<vector<int>> dp(n + 1, vector<int> (2, 0));

        dp[1][0] = 0;
        dp[1][1] = -1 * prices[0];
        for (int i = 2; i <= n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], -1 * prices[i - 1]);
            //cout << dp[i][0] << " " << dp[i][1] << endl;
        }
        //cout << endl;

        return dp[n][0];
    }
};
