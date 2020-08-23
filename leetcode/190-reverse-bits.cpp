
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        /*
         * 分治法
         * 1. 将32位分为2个16位的块，交换位置
         * 2. 将每个16位分为2个8位的块，交换位置
         * 3. 将每个8位分为2个4位的块，交换位置
         * 4. 将每个4位分为2个2位的块，交换位置
         * 5. 将每个2位分为2个1位的块，交换位置
         */
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);

        return n;
    }
};

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ret = 0;
        int power = 31;

        /* 循环处理每一位 */
        while (n) {
            ret += (n & 1) << power;
            n /= 2;
            power--;
        }

        return ret;
    }
};
