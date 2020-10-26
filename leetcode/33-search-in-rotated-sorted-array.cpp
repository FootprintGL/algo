


class Solution {
public:
    int search(vector<int>& nums, int target) {
        /* 二分查找 - 中间节点吧数组分成2部分，一部分有序，另一部分可能有序也可能无序 */
        int n = nums.size();

        if (n == 1)
            return target == nums[0] ? 0 : -1;

        int l = 0, r = n - 1, m;

        while (l <= r) {
            m = l + (r - l) / 2;

            if (nums[m] == target)
            /* 找到target */
                return m;

            if (nums[l] <= nums[m]) {
                /* 左边有序 */
                if (target >= nums[l] && target < nums[m]) {
                    /* 在左边 */
                    r = m - 1;
                } else {
                    /* 在右边 */
                    l = m + 1;
                }
            } else {
                /* 右边有序 */
                if (target > nums[m] && target <= nums[r]) {
                    /* 在右边 */
                    l = m + 1;
                } else {
                    /* 在左边 */
                    r = m - 1;
                }
            }
        }

        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /* 二分查找 - 中间节点吧数组分成2部分，一部分有序，另一部分可能有序也可能无序 */
        int n = nums.size();

        if (n == 1)
            return target == nums[0] ? 0 : -1;

        int l = 0, r = n - 1, m;

        while (l <= r) {
            m = l + (r - l) / 2;

            if (nums[m] == target)
            /* 找到target */
                return m;

            if (nums[0] <= nums[m]) {
                /* 左边有序 */
                if (target >= nums[0] && target < nums[m]) {
                    /* 在左边 */
                    r = m - 1;
                } else {
                    /* 在右边 */
                    l = m + 1;
                }
            } else {
                /* 右边有序 */
                if (target > nums[m] && target <= nums[n - 1]) {
                    /* 在右边 */
                    l = m + 1;
                } else {
                    /* 在左边 */
                    r = m - 1;
                }
            }
        }

        return -1;
    }
};

class Solution {
public:
    /* 二分法 - 已排序数组中查找target */
    int helper(vector<int> &nums, int left, int right, int target) {
        int ans = -1;
        int mid = 0;

        while (left <= right) {
            //cout << left << " " << right << endl;
            if (left == right && target == nums[left])
                return left;

            mid = left + (right - left) / 2;
            if (target < nums[mid])
                right = mid - 1;
            else if (target > nums[mid])
                left = mid + 1;
            else
                return mid;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int ans = -1;
        int len = nums.size();
        int left, right, mid;

        if (len == 0)
            return ans;

        if (len == 1)
            return target == nums[0] ? 0 : -1;

        if (nums[0] < nums[len - 1])
            return helper(nums, 0, len - 1, target);

        /* 二分法 - 找到最小元素位置为left,数组分割成左右两个已排序数组 */
        left = 0; right = len - 1;
        while (left <= right) {
            if (left == right || nums[left] < nums[right]) {
                break;
            }
            mid = left + (right - left) / 2;
            if (nums[mid] < nums[right])
                right = mid;
            else if (nums[mid] > nums[right])
                left = mid + 1;
        }

        /* 找到最小元素位置为left */
        if (target < nums[0])
            /* target在[left, len-1] */
            ans = helper(nums, left, len - 1, target);
        else if (target > nums[0])
            /* target在[0, left - 1] */
            ans = helper(nums, 0, left - 1, target);
        else
            ans = 0;

        return ans;
    }
};
