

class Solution {
public:
    int trailingZeroes(int n) {
        /*
         * 尾0的格式实际是 *10的个数， 就是求 2 * 5的个数
         * 偶数一定比5多，实际是求5的个数
         * 25有2个质因子5，125有3个质因子5
         * res = n / 5 + n / 5 /5 + n / 5 / 5 / 5,...
         */
        int res = 0;

        while (n) {
            int cur = n / 5;
            res += cur;
            n /= 5;
        }

        return res;
    }
};
