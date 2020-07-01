class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int sums[len + 1];
        int res = INT_MAX, start = 0, sum = 0;
        int i, j;

        /* 特殊情况处理 */
        if (len == 0)
            return 0;
        if (len == 1)
            return (nums[0] >= s);
        /*
         * 前缀和
         * 定义一个长度为len + 1的数组保存前缀和，sums[0]为0，方便计算字串和
         * sums[j] - sums[i]为(i, j]的子数组的和
         */
        sums[0] = 0;
        for (i = 0; i < len; i++) {
            sum += nums[i];
            sums[i + 1] = sum;
        }
        /* 双指针 */
        i = 0;
        j = i + 1;
        while (j <= len) {
            /* 向右移动j，找到最小的j, 使得(i, j]子数组和大于等于s */
            while (j <= len && sums[j] - sums[i] < s)
                j++;
            /* 如果没找到，说明从i到结尾所有元素和小于s，结束循环*/
            if (j == len + 1)
                break;
            /* 找到最短长度1，直接返回 */
            if (j - i == 1)
                return 1;
            /* 更新最小字串长度 */
            if (res > j - i)
                res = j - i;
            /* 向右移动i，直到(i, j]子数组和小于s */
            while (i < j && sums[j] - sums[i] >= s)
                i++;
            /* 找到最短长度1，直接返回 */
            if (i == j)
                return 1;
            /* 更新最小字串长度 - 此时(i, j]子数组和已小于s，长度为j - i + 1 */
            if (res > j - i + 1)
                res = j - i + 1;
        }

        return (res == INT_MAX) ? 0 : res;
    }
};
