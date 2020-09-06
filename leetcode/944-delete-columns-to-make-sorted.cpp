

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        /* 逐列比较，如果发现降序列，删除该列 */
        int n = A.size();
        vector<int> rm;
        int i, j;

        for (j = 0; j < A[0].length(); j++) {
            for (i = 1; i < n; i++) {
                if (A[i][j] < A[i - 1][j]) {
                    /* 降序 */
                    rm.push_back(j);
                    break;
                }
            }
        }

        return rm.size();
    }
};
