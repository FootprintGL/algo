

class Solution {
public:
    bool isPowerOfTwo(int n) {
        /*
         * 2的幂的二进制表示中只有一个1
         * n & (n - 1)可以消除n最右边的1
         * 如果n为2的幂，必满足下面的条件
         * 1. n > 0
         * 2. (n & (n - 1)) == 0
         */
        return n > 0 && (n & (n - 1)) == 0;
    }
};


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;

        while (n % 2 == 0)
            n >>= 1;

        return n == 1;
    }
};
