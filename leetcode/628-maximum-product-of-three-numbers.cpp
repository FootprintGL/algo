
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        /*
         * 分类讨论
         * 没有负数 - 最大的三个相乘
         * 没有正数 - 最大的三个相乘
         * 有正有负 - 最大的三个正数相称或最大的一个证书和最小的2个负数相乘
         */
        sort(nums.begin(), nums.end());
        int n = nums.size(), res;

        if (nums[0] >= 0 || nums[n - 1] <= 0) {
            res = nums[n - 1] * nums[n - 2] * nums[n - 3];
        } else {
            res = max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
        }

        return res;
    }
};
