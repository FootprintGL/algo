


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        /*
         * 二分
         * nums[-1]和nums[n]为负无穷大，相邻元素不相等
         * 可以从头开始遍历数组，检查nums[i]是否大于下一个nums[i + 1]即可判断nums[i]是否为峰值
         *      1 所有元素降序排列 - 第一个元素即峰值
         *      2 所有元素升序排列 - 最后一个元素为峰值
         *      3 峰值在中间 - 满足nums[i] > nums[i + 1]
         * 找到中间值mid，如果mid处在下降坡度，则左边有峰值，如果mid处在上升坡度，右边有峰值
         */
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[m + 1])
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};



class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        /*
         * 二分
         * nums[-1]和nums[n]为负无穷大，相邻元素不相等
         * 可以从头开始遍历数组，检查nums[i]是否大于下一个nums[i + 1]即可判断nums[i]是否为峰值
         *      1 所有元素降序排列 - 第一个元素即峰值
         *      2 所有元素升序排列 - 最后一个元素为峰值
         *      3 峰值在中间 - 满足nums[i] > nums[i + 1]
         * 找到中间值mid，如果mid处在下降坡度，则左边有峰值，如果mid处在上升坡度，右边有峰值
         */
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1])
                return i;
        }

        return n - 1;
    }
};



class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 0;

        /* nums[-1]和nums[n]为无穷大 */
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 2] < nums[n - 1])
            return n - 1;

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                return i;
        }

        return -1;
    }
};
