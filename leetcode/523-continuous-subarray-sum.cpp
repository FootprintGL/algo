


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2)
            return false;

        /* 前缀和 */
        vector<int> sums(n + 1, 0);
        int i, j;
        for (i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        for (i = 1; i < n; i++) {
            for (j = i + 1; j <= n; j++) {
                if (k == 0) {
                    if ((sums[j] - sums[i - 1]) == 0)
                        return true;
                } else {
                    /* 判断子数组能否被k整除 */
                    if ((sums[j] - sums[i - 1]) % k == 0)
                        return true;
                }
            }
        }

        return false;
    }
};
