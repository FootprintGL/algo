class Solution {
public:
    int waysToStep(int n) {
        int f3, f2, f1, f;
        int i;

        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        /* 
         * 动态规划
         * f3 -> f(i - 3), f2 -> f(i - 2), f1 -> f(i - 1), f -> f(i)
         * 第i个阶梯可以从三种方式到达
         * 从i - 1跨1步
         * 从i - 2跨2步
         * 从i - 3跨3步
         * dp[i] = f[i - 1] + f(i - 2) + f(i - 3)
         * 返回dp[n] - 注意整数溢出情况
         */
        f3 = 1;
        f2 = 1;
        f1 = 2;

        for (i = 3; i <= n; i++) {
            f = (f3 + f2) % 1000000007;
            f = (f + f1) % 1000000007;
            f3 = f2;
            f2 = f1;
            f1 = f;
        }

        return f;
    }
};
