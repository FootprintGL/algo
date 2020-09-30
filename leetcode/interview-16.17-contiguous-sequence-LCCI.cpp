

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
         * 动态规划
         * dp[i] - 以nums[i]为结尾的总和最大的连续数列
         * dp[i] = max{dp[i - 1] + nums[i], nums[i]}
         * 边计算边更新最大值
         */
        int res, n = nums.size();
        vector<int> dp(n, 0);

        if (n == 0)
            return 0;

        res = dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }

        return res;
    }
};
