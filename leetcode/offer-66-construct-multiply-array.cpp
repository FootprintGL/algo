

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        /*
         * B[i] = A[0] * ... * A[i - 1] * 1 * A[i + 1] * ... * A[n - 1]
         * B[i]为左半部分的乘积乘以右半部分的乘积
         */
        int n = a.size(), i;
        vector<int> res(n, 1);

        /* 计算左半部分的乘积 */
        int left = 1;
        for (i = 0; i < n; i++) {
            res[i] = left;
            left *= a[i];
        }

        /* 加入右半部分的乘积 */
        int right = 1;
        for (i = n - 1; i >= 0; i--) {
            res[i] *= right;
            right *= a[i];
        }

        return res;
    }
};
