

class Solution {
public:
    int flipLights(int n, int m) {
        /*
         * 假设1/2/3/4操作了a/b/c/d次
         * 1的状态为 (1 + a + c + d) % 2
         * 2的状态为 (1 + a + b)
         * 3的状态为 (1 + a + c)
         * 4的状态为 (1 + a + b + d)
         * 当1 == 3时，d为偶数，2 == 4
         * 当1 != 3时，d为奇数，2 != 4
         * 灯泡1和灯泡3可以决定灯泡4，即前3个灯泡可以决定所有灯泡状态
         */
        n = min(n, 3);

        if (n == 0)
            return 0;

        if (m == 0)
        /* 1 - 全亮 */
            return 1;

        if (m == 1) {
            if (n == 1)
                /* 1/0 */
                return 2;
            else if (n == 2) {
                /* 00/10/01 */
                return 3;
            } else if (n == 3) {
                /* 000/101/010/011 */
                return 4;
            }
        }

        if (m == 2) {
            if (n == 1)
                /* 1/0 */
                return 2;
            else if (n == 2)
                /* 11/00/01/10 */
                return 4;
            else
                /* 111/000/100/001/110/101/010 */
                return 7;
        }

        return n == 1 ? 2 : n == 2 ? 4 : 8;
    }
};
