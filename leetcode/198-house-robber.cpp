class Solution {
public:
    int rob(vector<int>& nums) {
        int f, f1, f2;
        int n = nums.size();
        int i;

        /* 特殊情况处理 */
        if (n == 0)
            return 0;
        else if (n == 1)
            return nums[0];
        else if (n ==2)
            return max(nums[0], nums[1]);

        /*
         * 动态规划
         * f(0) = nums[0]
         * f(1) = max(nums[0], nums[1])
         * f(i) = max(f(i - 1) + nums[i], f(i - 1))
         * 最后结果为f(n - 1)
         * f(i)只与f(i - 1)和f(i - 2)有关，利用滚动数组优化空间
         */
        f2 = nums[0];
        f1 = max(nums[0], nums[1]);
        for (i = 2; i < n; i++) {
            f = max(nums[i] + f2, f1);
            f2 = f1;
            f1 = f;
        }

        return f;
    }
};
