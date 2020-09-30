

class Solution {
public:
    void reverse(vector<int> &arr) {
        int l = 0, r = arr.size() - 1;

        while (l <= r) {
            int tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            l++;
            r--;
        }
    }

    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        vector<int> mask(n, 1);

        /* 翻转 */
        for (int i = 0; i < m; i++) {
            reverse(A[i]);
        }

        /* 反转 */
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] ^= mask[j];
            }
        }

        return A;
    }
};
