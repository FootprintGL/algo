class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> dp(n, 0);
        int i;

        if (n == 0)
            return 0;
        /*
         * 动态规划
         * 如果dp[i - 1] <= 0，dp[i] = nums[i]
         * 如果dp[i - 1] > 0, dp[i] = dp[i - 1] + nums[i]
         */
        res = dp[0] = nums[0];
        for (i = 1; i < n; i++) {
            if (dp[i - 1] <= 0)
                dp[i] = nums[i];
            else
                dp[i] = dp[i - 1] + nums[i];
            if (dp[i] > res)
                res = dp[i];
        }

        return res;
    }
};
