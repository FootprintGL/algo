


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        /*
         * 动态规划
         * 两种情况
         *      1. 连续子数组在整个数组内部
         *      2. 连续子数组跨越数组。计算整个数组之和，减去内部连续子数组的最小值
         */
        int n = A.size(), i;

        if (n == 0)
            return 0;

        int sum = A[0], premax = A[0], premin = A[0];
        int maximum = A[0], minimum = A[0];

        for (i = 1; i < n; i++) {
            sum += A[i];
            premax = max(premax + A[i], A[i]);
            premin = min(premin + A[i], A[i]);
            maximum = max(maximum, premax);
            minimum = min(minimum, premin);
        }

        return sum == minimum ? maximum : max(maximum, sum - minimum);
    }
};
