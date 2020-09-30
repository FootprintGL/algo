

class Solution {
public:
    int binaryGap(int N) {
        int res = 0, loop = 0;
        int prev = 0;
        /* 转换为无符号数进行以为操作 */
        unsigned int tmp = N;

        while (tmp) {
            int bit = tmp & 1;
            loop++;

            if (bit == 1) {
                if (prev == 0) {
                    prev = loop;
                } else {
                    res = max(res, loop - prev);
                    prev = loop;
                }
            }

            tmp >>= 1;
        }

        return res;
    }
};
