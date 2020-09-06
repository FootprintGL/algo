

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        /*
         * 动态规划
         * dp[i] - 数组可以组合成i的个数
         * dp[i] = sum(dp[i - nums[j]]), j = 0 -> n - 1, i - nums[j] >= 0
         * dp[0] = 1 -> 如果i刚好和某个nums[j]相等，成为一种解决方案
         * 结果为dp[target]
         */
        int n = nums.size();
        if (n == 0)
            return 0;

        //vector<int> dp(target + 1, 0); //int型会越界 - [3,33,333] 10000
        //int -> 溢出，long -> 溢出，long long -> 溢出, unsigned int通过
        vector<unsigned int> dp(target + 1, 0);
        int i, j;
        dp[0] = 1;

        for (i = 1; i <= target; i++) {
            for (auto num : nums) {
                if (i >= num)
                    dp[i] = dp[i] + dp[i - num];
            }
            /*
            for (j = 0; j < n; j++) {
                if (i - nums[j] >= 0)
                    dp[i] += dp[i - nums[j]];
            }
            */
        }

        return dp[target];
    }
};
