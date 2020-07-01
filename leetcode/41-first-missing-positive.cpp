iclass Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        int temp;
        int i, j;

        /* 
         * 最小的正整数小于等于N, 假设nums存放1~N, num[i]存放i + 1，先归位。
         * 如果发现nums[i]在[0,len]内并且nums[i] != i + 1, 则交换nums[i] 和 nums[num[i] - 1]
         * 新交换到i位置的元素需要继续检测处理，直到nums[i]等于i + 1或者nums[i]不在[1,len]范围内为止
         * 处理下一位置元素，循环结束，所有元素归为，然后遍历数组，如果找到num[i] != i + 1
         * 则缺失的数字就是i + 1, 如果找不到则缺失的是len + 1，时间复杂度O(n),空间复杂度O(1)
         */
        for (i = 0; i < len; i++) {
            while (nums[i] <= len && nums[i] > 0 && nums[i] != (i + 1)) {
                j = nums[i] - 1;
                /* 跳过重复元素 - 否则死循环。 */
                if (nums[i] == nums[j])
                    break;
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }
        }

        for (i = 0; i < len; i++) {
            if (nums[i] != i + 1) {
                return (i + 1);
            }
        }

        return (len + 1);
    }
};
