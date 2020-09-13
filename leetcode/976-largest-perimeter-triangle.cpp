
class Solution {
public:

    int largestPerimeter(vector<int>& A) {
        /* 如果2边之和大于第三边，可以组成三角形 */

        /* 从大到小排序 */
        sort(A.rbegin(), A.rend());

        for (int i = 2; i < A.size(); i++) {
            if (A[i] + A[i - 1] > A[i - 2])
                return A[i] + A[i - 1] + A[i - 2];
        }

        return 0;
    }
};
