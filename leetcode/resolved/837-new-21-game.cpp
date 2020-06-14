class Solution {
public:
    double new21Game(int N, int K, int W) {
        vector<double> dp (K + W, -1);
        double sum = 0;
        int i;

        /*
         * 动态规划
         * dp[i]表示从得分为x的情况开始游戏并获胜的概率，求dp[0]
         * K <= x <= (N, K + W - 1)是dp[x] = 1, x > min(N, K + W - 1)时dp[x] = 0
         * 状态转移方程为: dp[x] = (dp[x + 1] + dp[x + 2] + ... + dp[x + w])/W
         * 可以转换为: 
         * dp[x] - dp[x + 1] = (dp[x + 1] - dp[x + W + 1])/W
         * dp[x] = (dp[x + 1] + dp[x + W + 1])/W + dp[x + 1]
         */

        /* 计算dp[K] ~ dp[K + W - 1] */
        for (i = 1; i <= W; i++) {
            if (K - 1 + i <= N) {
                sum++;
                dp[K - 1 + i] = 1;
            } else
                dp[K - 1 + i] = 0;
        }

        /* 注意K,N,W的取值范围: 0 <= K <= N <=10000, 1 <= W <= 10000 */
        if (K >= 1) {
            /* 计算dp[K - 1] */ 
            dp[K - 1] = sum/W;
        }

        if (K >= 2) {
            /* dp[0] ~ dp[K-3]保存第1 ~ K - 2个*/
            for (i = K - 2; i >= 0; i--) {
                dp[i] = (dp[i + 1] - dp[i + W + 1]) / W + dp[i + 1];
            }
        }

        return dp[0];
    }
};

