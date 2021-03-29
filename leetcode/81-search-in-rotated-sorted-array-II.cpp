

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        /*
         * 二分查找
         * nums[start] == nums[mid], 分不清到底前面有序还是后面有序，start++即可，相当于去掉一个重复项
         * nums[start] < nums[mid], 左边有序，nums[start] < target < nums[mid],在左边找，否则在右边找
         * nums[start] > nums[mid], 右边有序，nums[mid] < target < nums[end],在右边找，否则在左边找
         */
        int n = nums.size();
        if (n == 0)
            return false;

        int start = 0, end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
                return true;

            if (nums[start] == nums[mid]) {
                start++;
                continue;
            }

            if (nums[start] < nums[mid]) {
                /* 左边有序 */
                if (target >= nums[start] && target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            } else {
                /* 右边有序 */
                if (target > nums[mid] && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return false;
    }
};
