


class Solution {
public:


    int stoneGameII(vector<int>& piles) {
        int len = piles.size();
        vector<vector<int>> dp(len, vector<int>(len + 1, -1));
        vector<int> sum(len + 1, 0);
        int i, j, k;

        /* 计算后缀和 */
        for (i = len - 1; i >= 0; i--) {
            sum[i] = sum[i + 1] + piles[i];
        }

        /*
         * 动态规划
         * dp[i][j] - 剩下i -> len - 1，当前player最多能拿多少颗石子
         * 如果i + 2 * j >= len - 1, 可以全部拿完，dp[i][j] = sum[i->len-1]
         * dp[i][j] = max{sum[i->len - 1] - dp[i + x][max{x, j}]} x: 1 -> 2 * j
         * 否则剩下的总石子数固定，给对方留的少，自己就拿得多
         * 结果为dp[0][1]
         */
        for (i = len - 1; i >= 0; i--) {
            for (j = 1; j <= len; j++) {
                if (i + 2 * j >= len) {
                    dp[i][j] = sum[i];
                } else {
                    for (k = 1; k <= 2 * j; k++) {
                        if (dp[i][j] == -1 || dp[i][j] < sum[i] - dp[i + k][max(k, j)])
                            dp[i][j] = sum[i] - dp[i + k][max(k, j)];
                    }
                }
            }
        }

        return dp[0][1];
    }
};
