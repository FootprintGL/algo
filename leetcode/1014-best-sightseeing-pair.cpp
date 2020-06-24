class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int max1, max, n = A.size();
        int i, j;

        /* 暴力循环 O(n^2) - 超时 */
        /*
        max = A[0] + A[1] - 1;
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if ((A[i] + A[j] + i - j) > max) {
                    max = A[i] + A[j] + i - j;
                }
            }
        }
        */

        /*
         * A[i] + A[j] + i - j -> A[i] + i + A[j] - j
         * j位置的最大值就是从0到j - 1的A[i] + i的最大值加上A[j] - j
         * 一次循环 O(n^2)
         */
        max1 = A[0];
        max = A[0] + A[1] - 1;
        for (i = 1; i < n; i++) {
            if (A[i - 1] + i - 1 > max1)
                max1 = A[i - 1] + i - 1;

            if (max1 + A[i] - i > max)
                max = max1 + A[i] - i;
        }

        return max;
    }
};
