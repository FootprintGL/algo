

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int len = stoneValue.size();
        vector<int> dp(len + 3, -1);
        vector<int> sum(len + 1, 0);
        int i, j, k;

        /* 计算后缀和 */
        for (i = len - 1; i >= 0; i--) {
            sum[i] = sum[i + 1] + stoneValue[i];
        }

        /*
         * 动态规划 - 同1140 - 石子游戏II
         * dp[i]为剩下i->len - 1石头堆，当前玩家最多能获得多少分
         * 如果只剩下一堆，必须拿走dp[len - 1] = sum[len - 1]
         * dp[i] = max{sum[i->len - 1] - dp[i + j]} j: 1 -> 3
         * 如果i + j > len时，dp[i + j] = 0
         * 剩下的总石子数固定，给对方留的少，自己就拿得多
         * 结果为dp[0]
         */
        for (i = len - 1; i >= 0; i--) {
            if (i == len - 1)
                dp[i] = sum[i];
            else {
                dp[i] = sum[i] - dp[i + 1];
                for (j = 2; j <= 3; j++) {
                    if (dp[i] < sum[i] - dp[i + j])
                        dp[i] = sum[i] - dp[i + j];
                }
            }
        }
/*
        cout << "dp: " << endl;
        for (i = len - 1; i >= 0; i-- )
            cout << dp[i] << " ";
        cout << endl;
*/
        if (dp[0] > sum[0] - dp[0])
            return "Alice";
        else if (dp[0] < sum[0] - dp[0])
            return "Bob";
        else
            return "Tie";
    }
};
