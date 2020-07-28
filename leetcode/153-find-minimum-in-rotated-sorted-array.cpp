


/* 迭代算法 */
class Solution {
public:

    int findMin(vector<int>& nums) {
        int ans;
        int left, right, mid;

        /* 二分法 */
        left = 0; right = nums.size() - 1;
        while (left <= right) {
            if (left == right || nums[left] < nums[right]) {
                ans = nums[left];
                break;
            }
            mid = left + (right - left) / 2;
            if (nums[mid] < nums[right])
                right = mid;
            else if (nums[mid] > nums[right])
                left = mid + 1;
        }

        return ans;
    }
};

/* 递归算法 */
class Solution {
public:
    void helper(vector<int>& nums, int left, int right, int &ans) {
        if (left >= right || nums[left] < nums[right]) {
            ans = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[right]) {
            helper(nums, left, mid, ans);
        } else if (nums[mid] > nums[right]) {
            helper(nums, mid + 1, right, ans);
        }
    }
    int findMin(vector<int>& nums) {
        int ans;
        /* 二分法 */
        helper(nums, 0, nums.size() - 1, ans);
        return ans;
    }
};
