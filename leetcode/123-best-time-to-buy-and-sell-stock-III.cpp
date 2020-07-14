
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int> (3, INT_MIN + 100000)));

        if (n <= 1)
            return 0;

        /*
         * 动态规划
         * dp[i][j][k] - 第i天所能获得的最大利润
         * i -> 第i天
         * j -> 第i天是持有股票还是持有现金，0表示现金，1表示股票
         * k -> 第几次交易[0,1,2]
         * dp[i][0][0] - 持有现金，没有交易
         * dp[i][0][0] = 0
         *
         * dp[i][0][1] - 持有现金，一次交易
         * dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][1][0] + prices[i])
         *
         * dp[i][0][2] - 持有现金，二次交易
         * dp[i][0][2] = max(dp[i - 1][0][2], dp[i - 1][1][1] + prices[i])
         *
         * dp[i][1][0] - 持有股票，没有交易
         * dp[i][1][0] = dp[i - 1][1][0]
         *
         * dp[i][1][1] - 持有股票，一次交易
         * dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][1] - prices[i])
         *
         * dp[i][1][2] - 持有股票，二次交易 - 最多二次交易，不可能，两次交易之后再买入股票，盈利减少
         */
        dp[0][0][0] = 0;
        dp[0][1][0] = -prices[0];

        for (int i = 1; i < n; i++) {
            dp[i][0][0] = 0;
            dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][1][0] + prices[i]);
            dp[i][0][2] = max(dp[i - 1][0][2], dp[i - 1][1][1] + prices[i]);
            dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][0][0] - prices[i]);
            dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][1] - prices[i]);
        }

        return max(0, max(dp[n - 1][0][1], dp[n - 1][0][2]));
    }
};




/* 下面的解法错误
输入[1,2,4,2,5,7,2,4,9,0]
输出12
预期结果13
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min, max, secmax;
        int i = 0;

        if (n == 0)
            return 0;
        /* 贪心算法: 找上升区间求差值 - 取最大的两个相加就是结果 */
        max = secmax = 0;
        while (i < n) {
            /* 找区间价格低谷 */
            while (i + 1 < n && prices[i + 1] < prices[i])
                i++;
            /* 处理完毕 - 没找到拐点 */
            if (i + 1 == n)
                break;
            /* 找到低谷 - 更新最低价格 */
            min = prices[i];
            /* 找区间价格峰值 */
            i = i + 1;
            while (i + 1 < n && prices[i + 1] > prices[i])
                i++;
            /* 找到峰值 - 更新最大和次大区间差值 */
            if (prices[i] - min > max) {
                secmax = max;
                max = prices[i] - min;
            } else if (prices[i] - min > secmax && prices[i] - min <= max) {
                secmax = prices[i] - min;
            }
        }

        return (secmax + max);
    }
};
