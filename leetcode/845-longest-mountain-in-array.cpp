



class Solution {
public:
    int longestMountain(vector<int>& A) {
        /*
         * 动态规划
         * left[i] - A[i]可以向左延伸的个数
         * right[i] = A[i]可以向右延伸的个数
         * 枚举最大的left[i] + right[i] + 1
         */
        int res = 0;
        int n = A.size();
        int i, j;

        if (n < 3)
            return res;
        
        /* 计算A[i]可以向左延伸的个数 */
        vector<int> left(n, 0);
        for (i = 1; i < n; i++) {
            if (A[i] > A[i - 1])
                left[i] = left[i - 1] + 1;
            else
                left[i] = 0;
        }

        /* 计算A[i]可以向右延伸的个数 */
        vector<int> right(n, 0);
        for (j = n - 2; j >= 0; j--) {
            if (A[j] > A[j + 1])
                right[j] = right[j + 1] + 1;
            else
                right[j] = 0;
        }

        for (i = 0; i < n; i++) {
            if (left[i] && right[i])
            /* 左右都可以延伸形成山脉 */
                res = max(res, left[i] + right[i] + 1);
        }

        return res;
    }
};
