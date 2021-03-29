

class Solution {
public:
    double myPow(double x, int n) {
        /*
         * 快速幂
         * 对于正整数n，设其二进制为bm...b3b2b1, bi为二进制某位的值
         * n = 1b1 + 2b2 + 4b3 + ... + 2 ^ (m - 1)bm - 二进制转换为十进制
         * x ^ n = x ^ (1b1 + 2b2 + 4b3 + ... + 2 ^ (m - 1)bm) = x ^ b1 * x ^ 2b2 * ... x ^ (2 ^ (m - 1) * bm)
         * 分解成两个问题
         *      1 计算x, x ^ 2, x ^ 4, ... , x ^ (2 ^ (m - 1))  -   循环赋值操作x = x * x
         *      2 获取二进制位的值
         *          n & 1判断n的最右边一位是否为1
         *          n >> 1右移一位，可以理解为删除一位
         * x ^ (2 ^ (i - 1) * bi) => 1, bi == 0
         * x ^ (2 ^ (i - 1) * bi) => x ^ (2 ^ (i - 1)), bi == 1
         */
        if (x == 0)
            return 0;

        long b = n;
        double res = 1.0;

        /* 指数为负 */
        if (b < 0) {
            x = 1 / x;
            b = -b;
        }

        /* 逐位处理 */
        while (b > 0) {
            if (b & 1)
                res *= x;
            x = x * x;
            b >>= 1;
        }

        return res;
    }
};
