

class Solution {
public:
    int getSum(int a, int b) {
        /* 异或即是无符号加法，与可以提取进位 - unsigned int防止移位时溢出 */
        unsigned ans, carrier;

        while (true) {
            ans = a ^ b;
            carrier = a & b;
            if (carrier == 0)
                break;
            a = ans;
            b = carrier << 1;
        }

        return ans;
    }
};
