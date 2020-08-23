


class Solution {
public:
    int helper(vector<int> &nums, int left, int right) {
        cout << left << " " << right << endl;
        if (left >= right)
            return (nums[left] == left) ? left : -1;

        int res;
        int mid = left + (right - left) / 2;
        if (nums[mid] != mid) {
            res = helper(nums, left, mid - 1);
            if (res != -1) {
                return res;
            } else {
                return helper(nums, mid + 1, right);
            }
        } else {
            return mid;
        }
    }

    int findMagicIndex(vector<int>& nums) {
        /*
         * 二分查找
         * 如果nums[mid] < mid, 可能在左，也可能在右
         * 先往左搜索[0,1,1,4,4]，再往右搜索[-1,-1,1,4,4]
         * 如果nums[mid] > mid, 可能在左，也可能在右
         * 先往左搜索[1,1,3,4,4]，再往右搜索[2,2,3,4,4]
         */
        return helper(nums, 0, nums.size() - 1);
    }
};
