

class Solution {
public:
    int maximum(int a, int b) {
        /* 利用符号位 - 正数符号位为0，负数的符号位为-1 */
        long t = (long)a - (long)b;
        int k = t >> 63;
        return (k + 1) * a - k * b;
    }
};
