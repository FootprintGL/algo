

class Solution {
public:
    int findfirstpos(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                /* 向左搜索找最左边的位置坐标 */
                right = mid;
            }
        }

        return nums[left] == target ? left : -1;
    }

    int findlastpos(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            //int mid = left + (right - left) / 2; -> left = 4, right = 5会出现死循环
            int mid = left + (right - left + 1) / 2;
            //cout << left << " " << right << " " << mid << endl;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                /* 向右搜索找最右边的位置坐标 */
                left = mid;
        }

        return nums[left] == target ? left : -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        /* 二分查找 */
        int n = nums.size();
        if (n == 0)
            return {-1, -1};

        int first = findfirstpos(nums, target);
        if (first == -1)
            return {-1, -1};

        int last = findlastpos(nums, target);
        return {first, last};
    }
};
