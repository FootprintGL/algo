
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int n = A.size();

        if (n == 1)
            return 0;

        /* 查找最大最小值, maxvalue - K和minvalue + K相交则为0，不想交则为他们的差值*/
        int minvalue = A[0], maxvalue = A[0];

        for (int i = 1; i < n; i++) {
            if (minvalue > A[i])
                minvalue = A[i];
            if (maxvalue < A[i])
                maxvalue = A[i];
        }

        return (maxvalue - K <= minvalue + K) ? 0 : maxvalue - K - minvalue - K;
    }
};
