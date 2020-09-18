

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        bool flag = true;
        int n = A.size();
        int i = 0;

        if (n < 3 || A[0] >= A[1])
            return false;

        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1]) {
                if (flag == false)
                    return false;
            } else if (A[i] < A[i - 1]) {
                flag = false;
            } else {
                return false;
            }
        }

        return !flag;
    }
};
