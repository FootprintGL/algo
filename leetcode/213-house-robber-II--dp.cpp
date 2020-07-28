


class Solution {
public:
    int rob(vector<int>& nums) {
        int res1, res2;
        int len = nums.size();
        vector<int> dp(len + 1, 0);
        int i;

        if (len == 0)
            return 0;

        if (len == 1)
            return nums[0];

        /*
         * 动态规划
         * 两种情况
         * 1. 偷1号房，同198 1 ～ n - 2
         * 2. 不偷1号房，同198 2 ～ n - 1
         */
        /* 偷1号房，1 ~ n - 1 */
        dp[0] = 0;
        dp[1] = nums[0];
        for (i = 2; i < len; i++)
                dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        res1 = dp[len - 1];

        /* 不偷1号房，2 ~ n */
        dp[0] = 0;
        dp[1] = nums[1];
        for (i = 2; i < len; i++)
                dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        res2 = dp[len - 1];

        return max(res1, res2);
    }
};
