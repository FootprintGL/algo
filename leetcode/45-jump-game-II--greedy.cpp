

class Solution {
public:
    int jump(vector<int>& nums) {
        /*
         * 贪心算法
         * 每次在可跳的范围内选择可以使得跳的更远的位置
         */
        int n = nums.size();
        /* 上次跳跃可达范围右边界 - 下次的最右起跳点 */
        int end = 0;
        /* 目前能够跳到的最远位置 */
        int maxpos = 0;
        /* 跳跃次数 */
        int steps = 0;

        for (int i = 0; i < n - 1; i++) {
            /* 当前位置最大跳跃距离 */
            maxpos = max(maxpos, i + nums[i]);
            if (i == end) {
                /* 到达当前可选的最后一个, 更新当前最大跳跃距离, 为下一个可选范围 */
                end = maxpos;
                steps++;
            }
        }

        return steps;
    }
};
