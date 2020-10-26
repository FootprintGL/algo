
/* 二进制分解 */
class Solution {
public:
    double myPow(double x, int n) {
        /*
         * 二进制分解
         * 18 = 0b(10010)
         * 18 = 1 * 2 ^ 4 + 0 * 2 ^ 3 + 0 * 2 ^ 2 + 1 * 2 ^ 1 + 0 * 2 ^ 0
         */
        double res = 1;
        /* 转换成long防止溢出 */
        long N = n;

        if (N < 0) {
            x = 1 / x;
            N *= -1;
        }

        while (N) {
            if (N & 1)
                res *= x;
            x *= x;
            N /= 2;
        }

        return res;
    }
};

/* 二分法 - x ^ n = (x ^ n / 2) * (x ^ n / 2)  */
class Solution {
public:
    double helper(double x, long n) {
        /* 
         * 注意:，虽然题目中告诉我们不需要考虑大数问题
         * 但是给出的 n 可以取到 −2147483648-2147483648−2147483648（整型负数的最小值
         * 因此，在编码的时候，需要将 n 转换成 long 类型。
         */
        /* 二分法 */
        if (n == 0 || x == 1.0)
            return 1;

        if (n % 2 == 0) {
            /* n为偶数 */
            double square = myPow(x, n / 2);
            return square * square;
        } else {
            /* n为奇数 */
            double square = myPow(x, (n - 1) / 2);
            return square * square * x;
        }
    }

    double myPow(double x, int n) {
        /* 二分法 */
        if (n < 0) {
            return 1 / helper(x, -1 * (long)n);
        }
        return helper(x, n);
    }
};


/* 超时 - 1 2147483647 */
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        int sign = 1;

        if (n < 0) {
            sign = -1;
            n = -1 * n;
        }

        while (n--) {
            res *= x;
        }

        return sign == 1 ? res : 1 / res;
    }
};
