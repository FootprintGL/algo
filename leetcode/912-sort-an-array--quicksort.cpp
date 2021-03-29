

class Solution {
public:
    int partition(vector<int> &nums, int left, int right) {
        int i = rand() % (right - left + 1) + left;
        swap(nums[i], nums[left]);
        int pivot = nums[left];
        int l = left, r = right;

        while (l < r) {
            while (l < r && nums[r] >= pivot)
                r--;
            while (l < r && nums[l] <= pivot)
                l++;
            if (l == r)
                break;
            swap(nums[l], nums[r]);
        }
        swap(nums[left], nums[l]);

        return l;
    }

    void quicksort(vector<int> &nums, int l, int r) {
        if (l < r) {
            int pos = partition(nums, l, r);
            quicksort(nums, l, pos - 1);
            quicksort(nums, pos + 1, r);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        /* 快速排序 */
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
};
