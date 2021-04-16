

class Solution {
public:
    int minOperations(vector<int>& nums) {
        /*
         * 反过来考虑，把nums变成全0
         * 操作1：某一个元素 - 1
         * 操作2: 所有元素 / 2 ==》 所有元素都为偶数时
         * 尽量多做除法，加速变换
         */
        int ops = 0;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        while (nums[n - 1] != 0) {
            /* 先做op1，调整成偶数 */
            for (int i = 0; i < n; i++) {
                if (nums[i] & 1) {
                    nums[i] -= 1;
                    ops++;
                }
            }
            /* 在做op2, 所有元素除以2 */
            if (nums[n - 1]) {
                for (int i = 0; i < n; i++) {
                    nums[i] /= 2;
                }
                ops++;
            }
        }

        return ops;
    }
};
