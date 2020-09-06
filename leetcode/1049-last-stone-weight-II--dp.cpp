class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        /*
         * 动态规划 - 0/1背包问题
         * 石头拿走还能放回去，问题等同于把石头分成2堆，2堆重量差最小
         * 假设总重量为sum, 转化为如果使两堆石头总重量接近sum/2
         * dp[i][j] - 容量为j，前i块石头最大能装多少
         * dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i])
         * 多加一行，方便计算，注意偏移
         * 每一行之和前一行相关，可以使用滚动降低到一维
         * 注意：如果从左往右更新，dp[j - stone]会限于dp[j]更新，所以需要从右向左更新
         */
        int n = stones.size();
        int sum = 0;
        int i, j;

        for (i = 0; i < n; i++)
            sum += stones[i];
        
        int target = sum / 2;
        vector<int> dp(target + 1, 0);

        for (i = 0; i < n; i++) {
            for (j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

/*
        for (i = 0; i <= target; i++) {
            cout << dp[i] << " ";
            if (i % 15 == 0)
                cout << endl;
        }
        cout << endl;
*/
        return sum - 2 * dp[target];
    }
};


class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        /*
         * 动态规划 - 0/1背包问题
         * 石头拿走还能放回去，问题等同于把石头分成2堆，2堆重量差最小
         * 假设总重量为sum, 转化为如果使两堆石头总重量接近sum/2
         * dp[i][j] - 容量为j，前i块石头最大能装多少
         * dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i])
         * 多加一行，方便计算，注意偏移
         */
        int n = stones.size();
        int sum = 0;
        int i, j;

        for (i = 0; i < n; i++)
            sum += stones[i];
        
        int target = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int> (target + 1, 0));

        for (j = 1; j <= target; j++) {
            for (i = 1; i <= n; i++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= stones[i - 1])
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
            }
        }

        return sum - 2 * dp[n][target];
    }
};
