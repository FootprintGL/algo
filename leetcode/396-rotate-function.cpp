

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        /*
         * 数学推导
         * F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n - 1) * Bk[n - 1]
         * F(k + 1) = 0 * Bk[n - 1] + 1 * Bk[0] + ... + (n - 1) * Bk[n - 2]
         * F(k + 1) - F(k) = 0 * (Bk[n - 1] - Bk[0]) + 1 * (Bk[0] - Bk[1]) + ... + (n - 1)(Bk[n - 2] - Bk[n - 1])
         * F(k + 1) - F(k) = Bk[0] + Bk[1] + ... + Bk[n - 2] - (n - 1)Bk[n - 1]
         * F(k + 1) - F(k) = Sum{Bk[i]} - n * Bk[n - 1]
         * F(k + 1) = F[k] + S - n * Bk[n - 1]
         */
        long n = A.size();
        long s = 0, t = 0, i;

        for (i = 0; i < n; i++) {
            s += A[i];
            t += i * A[i];
        }

        long res = t;
        for (i = n - 1; i >= 0; i--) {
            t += s - n * A[i];
            res = max(res, t);
        }

        return res;
    }
};
