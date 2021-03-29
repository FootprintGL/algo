

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        /*
         * 1 所有元素进行异或操作,最终得到一个异或值，因为有两个不同数字,这个值一定不为0
         * 2 取异或值最后一个二进制位为1的数字作为mask，如果是1，表示两个数字在这一位上不同
         * 3 基于mask进行分组，为0分为一组，为1分为一组。每一组内部只有一个数字出现一遍，其余数字出现两遍
         */
        vector<int> res(2, 0);

        /* 所有元素求异或 */
        long mask = 0;
        for (auto &num : nums)
            mask ^= num;

        /* 获得mask最低非零位 */
        mask = mask & (-mask);

        /* 分组并计算组内异或 */
        for (auto &num : nums) {
            if (num & mask)
                res[0] ^= num;
            else
                res[1] ^= num;
        }

        return res;
    }
};
