

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int flag = 0;

        /* 不能出现2个拐点 */
        for (int i = 1; i < A.size(); i++) {
            if (A[i] < A[i - 1]) {
                /* 递增 */
                if (flag == -1)
                    return false;

                flag = 1;
            } else if (A[i] > A[i - 1]) {
                /* 递减 */
                if (flag == 1)
                    return false;

                flag = -1;
            }
        }

        return true;
    }
};
