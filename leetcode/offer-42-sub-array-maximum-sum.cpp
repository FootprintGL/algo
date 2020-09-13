

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
         * 动态规划
         * dp[i] - 以nums[i]结尾的子数组的最大值
         * dp[i] = max(dp[i - 1] + nums[i], nums[i])
         */
        int res = -101;
        int n = nums.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            dp[i] = max(dp[i - 1] + nums[i - 1], nums[i - 1]);
            if (res < dp[i])
                res = dp[i];
        }

        return res;
    }
};
