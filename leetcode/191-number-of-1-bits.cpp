
class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t mask = 1, cnt = 0;

        /* n & (n - 1)会消除n最右边的1 */
        while (n) {
            n &= n - 1;
            cnt++;
        }

        return cnt;
    }
};


class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t mask = 1, cnt = 0;

        /* 逐位检测是否为1并统计 */
        for (int i = 0; i < 32; i++) {
            if (n & mask)
                cnt++;
            mask <<= 1;
        }

        return cnt;
    }
};
