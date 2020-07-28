
class Solution {
public:
    /* 二分法 */
    int helper(vector<int> &nums, int left, int right, int target) {
        if (left >= right) {
            if (target > nums[left])
                return left + 1;
            else
                return left;
        }

        int mid = left + (right - left) / 2;
        if (target > nums[mid])
            return helper(nums, mid + 1, right, target);
        else if (target < nums[mid])
            return helper(nums, left, mid - 1, target);
        else
            return mid;
    }

    int searchInsert(vector<int>& nums, int target) {
        return helper(nums, 0, nums.size() - 1, target);
    }
};
