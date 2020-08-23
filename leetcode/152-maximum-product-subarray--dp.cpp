


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
            return 0;

        /*
         * 动态规划
         * dp[i] - 以nums[i]结尾的连续子数组乘积的最大值
         * nums[i]可以单独乘积，也可以和前面dp[i - 1]组合乘积
         * 因为存在负数，必须同时计算最小值, 边计算边更新最大值
         * maxres[i] = max{nums[i]，num[i] * maxres[i - 1], num[i] * minres[i - 1]}
         * minres[i] = min{nums[i]，num[i] * maxres[i - 1], num[i] * minres[i - 1]}
         * maxres[0] = minres[0] = nums[0];
         */
        vector<int> maxres (n, 0);
        vector<int> minres (n, 0);
        int maxt, mint;
        int res;

        res = maxres[0] = minres[0] = nums[0];
        for (int i = 1; i < n; i++) {
            maxres[i] = max(maxres[i - 1] * nums[i], minres[i - 1] * nums[i]);
            maxres[i] = max(maxres[i], nums[i]);
            minres[i] = min(minres[i - 1] * nums[i], maxres[i - 1] * nums[i]);
            minres[i] = min(minres[i], nums[i]);
            if (res < maxres[i])
                res = maxres[i];
        }

        return res;
    }
};
