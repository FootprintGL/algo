


class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        /*
         * 相同的数字异或为0
         * 如果只有一个元素出现一次，其他的元素出现2次，则所有元素异或的结果即为出现一次的元素
         * 现在有2个元素出现一次，假设为a, b, 所有元素元素结果为x = a ^ b
         * 如果可以把数组分成2组
         *  1. 出现一次的元素属于不同分组
         *  2. 相同的元素在一个分组
         * 如果x的某以为1，表示a和b相应的位不同，可以以这一位来进行分组
         */
        int a = 0, b = 0;
        int x = 0;

        for (auto &num : nums)
            x ^= num;

        /* 找最低位的1 */
        int mask = 1;
        while ((x & mask) == 0)
            mask <<= 1;

        /* 以mask位置来进行分组 */
        for (auto &num : nums) {
            if (num & mask)
                a ^= num;
            else
                b ^= num;
        }

        return {a, b};
    }
};
