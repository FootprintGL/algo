

class Solution {
public:
    int minFlips(int a, int b, int c) {
        /*
         * 逐位统计处理
         * c在某位为1
         *      a. a为1，b为0
         *      b. a为0，b为1
         *      c. a为0，b为0   + 1
         *      d. a为1，b为1
         * c在某位为0
         *      a. a为1，b为0   + 1
         *      b. a为0，b为1   + 1
         *      c. a为0，b为0
         *      d. a为1，b为1   + 2
         */
        int cnt = 0;

        for (int i = 0; i < 32; i++) {
            int mask = 1 << i;
            if (c & mask) {
                if (((a & mask) == 0) && ((b & mask) == 0))
                    cnt++;
            } else {
                if ((a & mask) && ((b & mask) == 0))
                    cnt++;
                else if (((a & mask) == 0) && (b & mask))
                    cnt++;
                else if ((a & mask) && (b & mask))
                    cnt += 2;
            }
        }

        return cnt;
    }
};
