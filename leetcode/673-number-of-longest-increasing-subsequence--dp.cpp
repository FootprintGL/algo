

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        /*
         * 动态规划
         * dp[i] - 以nums[i]为结尾的最长递增子序列的长度
         * dp[i] = max{dp[j]} + 1, j: 0 -> i - 1; nums[j] < nums[i]
         * cnt[i] - 表示以nums[i]为结尾的最长子序列的个数
         * 如果dp[i] == dp[j] + 1, -> len[i] += len[j]
         * 如果dp[i] < dp[j] + 1, -> len[i] = len[j], dp[i] = dp[j] + 1
         * 边计算边更新最大子序列长度和个数
         */
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        int ans = 1, maxlen = 1;
        int i, j;

        for (i = 1; i < n; i++) {
            for (j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dp[i] == dp[j] + 1) {
                        /* 找到一组以nums[i]结尾的最长子序列，更新cnt[i] */
                        cnt[i] += cnt[j];
                    } else if (dp[i] < dp[j] + 1) {
                        /* 发现更长以nums[i]结尾的更长子序列，更新cnt[i] */
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }
            }
            if (dp[i] == maxlen) {
                /* dp[i]和当前最长子序列长度相等, 更新结果ans */
                ans += cnt[i];
            } else if (dp[i] > maxlen) {
                /* 找到更长的子序列，更新maxlen和结果ans */
                ans = cnt[i];
                maxlen = dp[i];
            }
        }
/*
        for (int i = 0; i < n; i++) {
            cout << dp[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < n; i++) {
            cout << cnt[i] << " ";
        }
        cout << endl;
*/
        return ans;
    }
};
