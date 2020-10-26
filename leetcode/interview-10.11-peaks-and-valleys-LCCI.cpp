

class Solution {
public:
    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    void wiggleSort(vector<int>& nums) {
        /*
         * 如果i为峰的位置，nums[i] < nums[i - 1], 交换
         * 如果i为谷的位置，nums[i] > nums[i - 1], 交换
         */
        for (int i = 1; i < nums.size(); i++) {
            if (i % 2) {
                /* 奇数 - 峰的位置 */
                if (nums[i] < nums[i - 1])
                    swap(nums, i, i - 1);
            } else {
                /* 偶数 - 谷的位置 */
                if (nums[i] > nums[i - 1])
                    swap(nums, i, i - 1);
            }
        }
    }
};
