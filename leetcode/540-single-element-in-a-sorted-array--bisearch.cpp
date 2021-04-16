

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        /*
         * 二分法
         * 有一个单数，数组共有奇数个元素
         * 如果中间的数和它后面的数相等
         *      a. 中间的数分割为两个偶数数组，单数在右边l = mid + 2
         *      b. 中间的数分割为两个奇数数组，单数在左边r = mid - 1
         * 如果中间的数和它前面的数相等
         *      a. 中间的数分割为两个偶数数组，单数在左边r = mid - 2
         *      b. 中间的数分割为两个奇数数组，单数在右边l = mid + 1
         * 前后都不相等，则中间的数即为所求的单数
         */
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (nums[m] == nums[m + 1]) {
                if ((r - m) % 2) {
                    r = m - 1;
                } else {
                    l = m + 2;
                }
            } else if (nums[m] == nums[m - 1]) {
                if ((r - m) % 2) {
                    l = m + 1;
                } else {
                    r = m - 2;
                }
            } else {
                return nums[m];
            }
        }

        return nums[l];
    }
};
