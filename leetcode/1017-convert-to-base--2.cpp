

class Solution {
public:
    string baseNeg2(int N) {
        /*
         * 如果余数为-1，可以把余数变成整数，再给商加1
         * -1 (-2) ^ k = (-2 + 1) * (-2) ^ k = -2 * (-2) ^ k + 1 * (-2) ^ k
         * = (-2) ^ (k + 1) + (-2) ^ k
         */
        if (N == 0)
            return "0";

        string res;
        while (N != 0) {
            int r = (N % (-2));
            res.insert(res.begin(), r != -1 ? r + '0' : 1 + '0');
            N /= -2;
            if (r == -1)
                N += 1;
        }

        return res;
    }
};
