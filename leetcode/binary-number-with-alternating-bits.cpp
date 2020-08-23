

class Solution {
public:
    bool hasAlternatingBits(int n) {
        /* 将n右移1位异或n，判断是否全1, 定义long避免越界 */
        long tmp = n ^ (n >> 1);
        return ((tmp & (tmp + 1)) == 0);
    }
};


class Solution {
public:
    bool hasAlternatingBits(int n) {
        /* n % 2得最后一位，n / 2 得到倒数第2位 */
        while (n != 0) {
            if ((n / 2 % 2) == (n % 2))
                return false;
            n /= 2;
        }
        return true;
    }
};
