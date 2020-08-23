


class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        /*
         * 问题的本质是求m和n的公共前缀
         * n & (n - 1)会消除n最右边的1
         */
        while (m < n) {
            n &= n - 1;
        }

        return n;
    }
};


class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        /*
         * 问题的本质是求m和n的公共前缀
         * 因为从m到n对应bit位上有一个为0，则结果对应bit位为0
         */
        int shift = 0;
        while (m < n) {
            m >>= 1;
            n >>= 1;
            shift++;
        }

        return m << shift;
    }
};
