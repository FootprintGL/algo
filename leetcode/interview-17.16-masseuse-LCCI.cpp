class Solution {
public:
    int massage(vector<int>& nums) {
        int n = nums.size();
        int f2, f1, f;
        int i;

        if (n == 0)
            return 0;
        /* 
         * 动态规划
         * dp[i] = max (dp[i - 2] + nums[i], dp[i - 1])
         * dp[0] = 0, dp[1] = nums[0], dp[2] = max(dp[0] + nums[2], dp[1])
         */
        f2 = 0;
        f = f1 = nums[0];
        for (i = 1; i < n; i++) {
            f = max(f1, f2 + nums[i]);
            f2 = f1;
            f1 = f;
        }

        return f;
    }
};
