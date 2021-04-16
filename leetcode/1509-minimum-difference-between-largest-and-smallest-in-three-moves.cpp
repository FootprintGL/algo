

class Solution {
public:
    int minDifference(vector<int>& nums) {
        /*
         * 求最大值和最小值差的最小值
         * 期望最小值变大，最大值变小，实际是求排序后，从两端
         * 移除3个数字所能得到的最大值和最小值之差的最小值
         */
        int res = INT_MAX;
        int n = nums.size();

        if (n <= 4)
            return 0;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < 4; i++) {
            res = min(res, nums[n - 4 + i] - nums[i]);
        }

        return res;

    }
};
