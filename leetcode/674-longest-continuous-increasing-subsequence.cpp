

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return n;

        /*
         * 滑动窗口
         * 当nums[right] <= nums[right - 1]时递增序列结束
         * 划分窗口 - 前面的递增子序列长度为[left, right) - 左闭右开
         * 注意在最后一个元素大于倒数第二个元素时需要特殊处理 - 递增子区间为[left, right], 左闭右闭
         */
        int left = 0, right = 1;
        int ans = 1;
        while (right < nums.size()) {
            if (nums[right] <= nums[right - 1]) {
                ans = max(ans, right - left);
                left = right;
            } else if (right == nums.size() - 1) {
                ans = max(ans, right - left + 1);
            }
            right++;
        }

        return ans;
    }
};
