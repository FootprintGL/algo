

class Solution {
public:
    int findTheWinner(int n, int k) {
        /*
         * 约瑟夫问题
         * 每杀掉一个人，下一个人成为头，相当与把数组向前移动了M位
         * 若已知N - 1个人时，胜利者的下标位置为f(N - 1, M), 则
         * N个人的时候，就是往后移动M位，因为有可能数组越界，超过的
         * 部分会接到头上，所以还要对N取模
         * f(N, M) = (f(N - 1, M) + M) % N
         * f(1, M) = 0
         */
        int p = 0;

        for (int i = 2; i <= n; i++) {
            p = (p + k) % i;
        }

        return p + 1;
    }
};
