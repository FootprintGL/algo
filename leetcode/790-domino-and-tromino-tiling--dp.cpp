

class Solution {
public:
    int numTilings(int N) {
        /*
         * 动态规划
         * dp[i][0] - 第i列铺满的方法
         * dp[i][1] - 第i列缺左上角的方法
         * dp[i][2] - 第i列缺右下角的方法
         * dp[i][0] = dp[i - 1][0] (i块竖放，i-1块竖放) + dp[i - 1][1](i - 1缺上口，卡口放)
         *      + dp[i - 1][2](i - 1缺下口，卡口放) + i >=2 ? dp[i - 2][0] : 0 (i， i-1块横放)
         * dp[i][1] = dp[i - 1][2] + i >= 2 ? dp[i - 2][0] : 0
         * dp[i][2] = dp[i - 1][1] + i >= 2 ? dp[i - 2][0] : 0
         * 边界dp[0][0] = 1, dp[0][1] = 0, dp[0][2] = 0
         * 结果为dp[n][0]
         */
        vector<vector<long>> dp(N + 1, vector<long> (3, 0));
        int M = 1000000007;
        int i;

        dp[0][0] = 1;
        for (i = 1; i <= N; i++) {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + (i >= 2 ? dp[i - 2][0] : 0);
            dp[i][0] %= M;
            dp[i][1] = dp[i - 1][2] + (i >= 2 ? dp[i - 2][0] : 0);
            dp[i][1] %= M;
            dp[i][2] = dp[i - 1][1] + (i >= 2 ? dp[i - 2][0] : 0);
            dp[i][2] %= M;
        }

        return dp[N][0];
    }
};
