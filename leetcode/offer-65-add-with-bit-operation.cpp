
class Solution {
public:
    int add(int a, int b) {
        /* 异或运算求和，与运算求进位 */
        while (b) {
            /* 进位 - int会溢出，转为无符号数，忽略符号位 */
            int c = (unsigned int)(a & b) << 1;
            /* 无进位和 */
            a ^= b;
            b = c;
        }

        return a;
    }
};
