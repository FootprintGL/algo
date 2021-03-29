

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
         * 双指针 - 快慢指针
         * 快指针 - 遍历整个数组
         * 慢指针 - 记录可以覆写数据的位置
         * 题目要求每个元素最多出现两次
         *      if (len < 2) nums[len++] = nums[i]
         *          如果len < 2, 不会出现3个连续相同元素，直接将新元素加入到新序列中，并更新新序列长度
         *      if (nums[i] != nums[len - 2])) nums[len++] = nums[i]
         *          如果新元素加入后不会和前两个元素构成3个相同元素, 就将新元素加入到新序列中，并更新新序列长度
         */
        int len = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (len < 2 || nums[i] != nums[len - 2])
                nums[len++] = nums[i];
        }

        return len;
    }
};
