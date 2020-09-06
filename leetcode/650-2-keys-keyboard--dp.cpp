

class Solution {
public:
    int minSteps(int n) {
        /*
         * 动态规划
         * dp[i] - 打印i个A的最少操作次数
         *      1. i为质数只能一个一个打印, dp[i] = i
         *      2. i为合数结果为分解因式结果之和，dp[i] = dp[j] + dp[i/j]
         * dp[0] = dp[1] = 0
         */
        vector<int> dp(n + 1, 0);
        int i, j;

        for (i = 2; i <= n; i++) {
            dp[i] = i;
            for (j = 2; j < n / 2; j++) {
                if (i % j == 0) {
                    dp[i] = dp[j] + dp[i / j];
                    break;
                }
            }
        }

        return dp[n];
    }
};


class Solution {
public:
    int minSteps(int n) {
        /*
         * 质数因子分解
         * 操作分为以C开头的多组，CPPPCPPCPPPPP -> {CPPP}, {CPP}, {CPPPPP}
         * 假设每组长度为g1,g2,..., 完成第一组字符串有g1个A，完成第二组有g1 * g2个A
         * 最终想要n = g1 * g2 * ... * gk个A，如果gi是合数，存在gi = p * q
         * 那么可以分解为2组，第一组一个C和p - 1个P，第二组一个C和q - 1个P
         * 分解之后的操作更少p + q <= p * q 等价于 pq - p - q + 1 - 1 >= 0
         * 即(p - 1)(q - 1) >= 1， p >= 2, q >= 2时成立
         */
        int ans = 0;
        int d = 2;

        while (n > 1) {
            while (n % d == 0) {
                ans += d;
                n /= d;
            }
            d++;
        }

        return ans;
    }
};
