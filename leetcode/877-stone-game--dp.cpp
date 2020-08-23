

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int len = piles.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        int i, j, size;

        /*
         * 动态规划
         * dp[i][j] - 剩下i到j堆时alex比lee多拿了多少颗石子
         * 如果剩下偶数堆，轮到alex拿
         * dp[i][j] = max{dp[i + 1][j] + piles[i], dp[i][j - 1] + piles[j]}
         * 如果剩下奇数堆，轮到lee拿
         * dp[i][j] = min{dp[i + 1][j] - piles[i], dp[i][j - 1] - piles[j]}
         * dp[i][i] = -piles[i] - 最后一堆轮到lee拿，为负值
         */
        /* 只剩下一堆 - 轮到lee拿 */
        for (i = 0; i < len; i++)
            dp[i][i] = -1 * piles[i];

        for (j = 2; j <= len; j++) {
            for (i = 0; i < len - j + 1; i++) {
                if (j % 2)
                /* 剩下奇数堆 - 轮到lee拿 */
                    dp[i][i + j - 1] = min(dp[i + 1][i + j - 1] - piles[i], dp[i][i + j - 2] - piles[i + j - 1]);
                else
                /* 剩下偶数堆 - 轮到alex拿 */
                    dp[i][i + j - 1] = max(dp[i + 1][i + j - 1] + piles[i], dp[i][i + j - 2] + piles[i + j - 1]);
            }
        }

        return (dp[0][len - 1] > 0);
    }
};
