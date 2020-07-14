/* 滚动数组优化空间 + k > n/2时可以采用贪婪算法（122题：股票II） */


class Solution {
public:
    /* 122-股票II - 贪婪算法 */
    int greedy(vector<int> &prices, int len) {
        int res = 0;
        for (int i = 1; i < len; i++) {
            if (prices[i - 1] < prices[i]) {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int t0j;
        int maximum;
        if (n <= 1)
            return 0;

        if(k >= n/2) {
            return greedy(prices, n);
        }
        /* 动态分配 - 防止溢出 */
        int (* dp)[2] = new int[k + 1][2];
        for (int i = 0; i <= k; i++) {
            dp[i][0] = 0;
            dp[i][1] = INT_MIN + 100000;
        }

        /*
         * 动态规划
         * dp[i][j][k] - 第i天所能获得的最大利润
         * i -> 第i天
         * j -> 第i天是持有股票还是持有现金，0表示现金，1表示股票
         * k -> 第几次交易[0,1,2,k]
         * dp[i][0][0] - 持有现金，没有交易
         * dp[i][0][0] = 0
         *
         * dp[i][0][1] - 持有现金，一次交易
         * dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][1][0] + prices[i])
         *
         * dp[i][0][2] - 持有现金，二次交易
         * dp[i][0][2] = max(dp[i - 1][0][2], dp[i - 1][1][1] + prices[i])
         *
         * ... ...
         *
         * dp[i][0][k] - 持有现金，k次交易
         * dp[i][0][2] = max(dp[i - 1][0][k - 1], dp[i - 1][1][k - 2] + prices[i])
         *
         * dp[i][1][0] - 持有股票，没有交易
         * dp[i][1][0] = dp[i - 1][1][0]
         *
         * dp[i][1][1] - 持有股票，一次交易
         * dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][1] - prices[i])
         *
         * ... ...
         *
         * dp[i][1][k - 1] - 持有股票，k - 1次交易
         * dp[i][1][k - 1] = max(dp[i - 1][1][1], dp[i - 1][0][k - 1] - prices[i])
         *
         * dp[i][1][k] - 持有股票，二次交易 - 最多二次交易，不可能
         *
         * 滚动数组优化空间
         */
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[0][1] = max(dp[0][1], dp[0][0] - prices[i]);
            for (int j = 1; j <= k; j++) {
                t0j = dp[j][0];
                dp[j][0] = max(dp[j][0], dp[j - 1][1] + prices[i]);
                if (j < k)
                    dp[j][1] = max(dp[j][1], t0j - prices[i]);
            }
        }

        maximum = 0;
        for (int i = 0; i <= k; i++) {
            maximum = max(maximum, dp[i][0]);
        }

        return maximum;
    }
};




/* 提交超时 - 执行超出内存限制 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int> (k + 1, INT_MIN + 100000)));
        int maximum;

        if (n <= 1)
            return 0;

        /*
         * 动态规划
         * dp[i][j][k] - 第i天所能获得的最大利润
         * i -> 第i天
         * j -> 第i天是持有股票还是持有现金，0表示现金，1表示股票
         * k -> 第几次交易[0,1,2,k]
         * dp[i][0][0] - 持有现金，没有交易
         * dp[i][0][0] = 0
         *
         * dp[i][0][1] - 持有现金，一次交易
         * dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][1][0] + prices[i])
         *
         * dp[i][0][2] - 持有现金，二次交易
         * dp[i][0][2] = max(dp[i - 1][0][2], dp[i - 1][1][1] + prices[i])
         *
         * ... ...
         *
         * dp[i][0][k] - 持有现金，k次交易
         * dp[i][0][2] = max(dp[i - 1][0][k - 1], dp[i - 1][1][k - 2] + prices[i])
         *
         * dp[i][1][0] - 持有股票，没有交易
         * dp[i][1][0] = dp[i - 1][1][0]
         *
         * dp[i][1][1] - 持有股票，一次交易
         * dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][1] - prices[i])
         *
         * ... ...
         *
         * dp[i][1][k - 1] - 持有股票，k - 1次交易
         * dp[i][1][k - 1] = max(dp[i - 1][1][1], dp[i - 1][0][k - 1] - prices[i])
         *
         * dp[i][1][k] - 持有股票，二次交易 - 最多二次交易，不可能
         */
        dp[0][0][0] = 0;
        dp[0][1][0] = -prices[0];

        for (int i = 1; i < n; i++) {
            dp[i][0][0] = 0;
            dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][0][0] - prices[i]);
            for (int j = 1; j <= k; j++) {
                dp[i][0][j] = max(dp[i - 1][0][j], dp[i - 1][1][j - 1] + prices[i]);
                dp[i][1][j] = max(dp[i - 1][1][j], dp[i - 1][0][j] - prices[i]);
            }
        }

        maximum = 0;
        for (int i = 0; i <= k; i++) {
            maximum = max(maximum, dp[n - 1][0][i]);
        }

        return maximum;
    }
};
