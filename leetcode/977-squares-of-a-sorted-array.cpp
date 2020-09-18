

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        /* 数组非递减 - 平方数非负部分非递减，负数部分非递增 */
        int n = A.size();
        vector<int> res(n, 0);
        int l = 0, r, i = 0;

        /* 找正负分界点 */
        while (l < n && A[l] < 0)
            l++;

        /* 双指针 - l指向最大的负数，r指向最小的非负正数 */
        r = l;
        l = l - 1;
        while (l >= 0 && r < n) {
            if (A[l] * A[l] <= A[r] * A[r]) {
                res[i++] = A[l] * A[l];
                l--;
            } else {
                res[i++] = A[r] * A[r];
                r++;
            }
        }

        while (l >= 0) {
            res[i++] = A[l] * A[l];
            l--;
        }

        while (r < n) {
            res[i++] = A[r] * A[r];
            r++;
        }

        return res;
    }
};
