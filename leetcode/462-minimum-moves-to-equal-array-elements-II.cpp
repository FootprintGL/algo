

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        /*
         * 寻找中位数
         * [n1, n2, ..., nk-1] nk [nk+1, ..., n2k - 1]，nk为中位数
         * 如果不以中位数为目标数，假设选n1...nk-1中某一个nl为目标数，对比以nk为目标的情况
         * nl...n2k-1区间多移动nk - nl次，而n1...nl-1区间少移动nk-nl次，结果显而易见
         * 多移动的区间长度大于少移动的区间长度，额外增加了移动次数
         */
        int n = nums.size();
        int res = 0;

        /* 排序 */
        sort(nums.begin(), nums.end());

        /* 如果n为偶数，取中间两个数任意一个都可以 */
        int mid = nums[n / 2];
        for (int i = 0; i < n; i++) {
            res += abs(nums[i] - mid);
        }

        return res;
    }
};
