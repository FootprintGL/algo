

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
         * 位运算 - 逐位处理
         * 把数看成32位的二进制，对于每一位的二进制1/0累加起来必是3N或3N+1
         * 3N代表目标值在这一位没有贡献，3N+1代表目标值对这一位有贡献(=1)
         * 然后将所有有贡献的位|起来就是结果
         */
        int ret = 0;

        for (int i = 0; i < 32; i++) {
            int mask = 1 << i;
            int cnt = 0;
            for (int j = 0; j < nums.size(); j++) {
                if ((nums[j] & mask) != 0)
                    cnt++;
            }
            if (cnt % 3)
                ret |= mask;
        }

        return ret;
    }
};
