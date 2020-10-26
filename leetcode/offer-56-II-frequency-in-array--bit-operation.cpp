

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
         * 考虑二进制形式，对于出现3次的数字每一位出现的次数都是3的倍数
         * 统计所有数字的各二进制为中1的个数对3取余，结果为出现一次的数字
         */
        int cnt[32] = {0};
        int i, cur, res = 0;

        /* 求所有元素每个位的和 */
        for (auto &num : nums) {
            for (i = 0; i < 32; i++) {
                if (num & (1 << i))
                    cnt[i]++;
            }
        }

        /* 每位对3取欲生成结果 */
        for (i = 0; i < 32; i++) {
            res <<= 1;
            res |= cnt[31 - i] % 3;
        }

        return res;
    }
};
