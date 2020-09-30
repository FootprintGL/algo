

class Solution {
public:
    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    void reverse(vector<int> &nums, int start) {
        int i = start;
        int j = nums.size() - 1;
        while (i <= j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }

    void nextPermutation(vector<int>& nums) {
        /*
         * 找更大的排列，就是从后面找一个较大的和前面小的交换
         * 如果排列本身递减，则是最大元素
         * 1. 从右向左第一个a[i], 使得a[i + 1] > a[i], a[i + 1]到结尾已经递减
         * 2. 从右向左找到第一个a[j]使得a[j] > a[i], 交换a[i], a[j]，A[i + 1]到结尾仍然递减
         * 3. 此时把a[i + 1]到结尾反转即为下一个更大的之
         */
        int n = nums.size();
        int i = n - 2, j = n - 1;

        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;

        if (i >= 0) {
            while (j > i && nums[i] >= nums[j])
                j--;
            swap(nums, i, j);
        }

        reverse(nums, i + 1);
    }
};
