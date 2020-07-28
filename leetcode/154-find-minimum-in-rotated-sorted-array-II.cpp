
class Solution {
public:
    /* 迭代算法 */
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int left, right, mid;
        /* 二分法 - 分治算法 */

        if (len == 0)
            return -1;

        left = 0;
        right = len - 1;
        while (left < right) {
            if (nums[left] < nums[right])
                break;
            mid = left + (right - left) / 2;
            if (nums[mid] < nums[right])
                right = mid;
            else if (nums[mid] > nums[right])
                left = mid + 1;
            else
                /* 相等时最小值在[left, right - 1]区间 */
                right = right - 1;
        }

        return nums[left];
    }
};

class Solution {
public:
    /* 迭代算法 */
    int findMin(vector<int>& nums) {
        int ans = 0;
        int len = nums.size();
        int left, right, mid;
        /* 二分法 - 分治算法 */
        
        if (len == 0)
            return -1;

        left = 0;
        right = len - 1;
        while (left <= right) {
            if (left == right || nums[left] < nums[right]) {
                ans = nums[left];
                break;
            }
            mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                /* 相等时最小值在[left, right - 1]区间 */
                right = right - 1;
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    /* 递归算法 */
    void helper(vector<int> &nums, int left, int right, int &ans) {
        if (left >= right) {
            ans = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[right]) {
                helper(nums, left, mid, ans);
        } else if (nums[mid] > nums[right]){
            helper(nums, mid + 1, right, ans);
        } else {
            /* 相等时最小值在[left, right - 1]区间 */
            helper(nums, left, right - 1, ans);
        }
    }

    int findMin(vector<int>& nums) {
        int ans = 0;
        /* 二分法 - 分治算法 */
        helper(nums, 0, nums.size() - 1, ans);
        return ans;
    }
};

class Solution {
public:
    /* 递归算法 */
    void helper(vector<int> &nums, int left, int right, int &ans) {
        if (left >= right) {
            ans = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[right]) {
                helper(nums, left, mid, ans);
        } else if (nums[mid] > nums[right]){
            helper(nums, mid + 1, right, ans);
        } else {
            /*
             * 相等时最小值可能在左边[3,1,3,3,3]
             * 也可能在右边 [3,3,1,3]
             * 甚至可能全部相等[3,3,3,3]
             */
            int t1, t2, t = nums[mid];
            helper(nums, left, mid - 1, t1);
            helper(nums, mid + 1, right, t2);
            ans = min(t1, t2);
            ans = min(ans, t);
        }
    }

    int findMin(vector<int>& nums) {
        int ans = 0;
        /* 二分法 - 分治算法 */
        helper(nums, 0, nums.size() - 1, ans);
        return ans;
    }
};
