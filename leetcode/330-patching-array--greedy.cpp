


class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        /*
         * 贪心
         * 对于正整数x，如果[1, x - 1]内的所有数字都被覆盖，且x在数组中，则区间[1, 2x - 1]内所有数字被覆盖
         * 加入x缺失，则至少需要在数组中补充一个小于等于x的数，才能覆盖x，否则无法覆盖x。如果补充x，则可以覆盖x，
         * 且满足补充的数字最少。在补充x之后，区间[1, 2x - 1]内的所有数字都被覆盖，下一个缺失的数字一定不会小于2x
         * 每次找到未被数组覆盖的最小整数x，在数组中补充x，然后寻找下一个未被覆盖的最小整数，重复直到[1, n]中所有
         * 数字都被覆盖
         * 令x的初始值为1，数组下标index为0，则初始条件下区间[1, x - 1]为空区间，满足区间内所有数字都被覆盖
         *      1 如果index在nums的下标范围内且num[index] <= x, 则将nums[index]的值加给x，并将index的值加1
         *          被覆盖的区间从[1, x - 1]扩展到[1, x + num[index] - 1]，对x的值更新以后，被覆盖的区间为[1, x - 1]
         *      2 否则x没有被覆盖，因此需要在数组中补充x，然后将x乘以2
         *          在数组中补充x后，被覆盖的区域从[1, x - 1]扩展到[1, 2x - 1]，对x更新后，被覆盖区间为[1, x - 1]
         * 重复操作，直到x的值大于n
         */
        int index = 0;
        long x = 1; //防止溢出
        int patches = 0;

        while (x <= n) {
            if (index < nums.size() && nums[index] <= x) {
                x += nums[index];
                index++;
            } else {
                x *= 2;
                patches++;
            }
        }

        return patches;
    }
};
