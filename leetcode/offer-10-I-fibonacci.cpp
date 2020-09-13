

class Solution {
public:
    
    int fib(int n) {
        int M = 1e9 + 7;

        if (n <= 1)
            return n;

        /* 
         * 动态规划
         * dp[i] = dp[i - 1] + dp[i - 2]
         * dp[0] = 0, dp[1] = 1
         * 结果为dp[n]
         */
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
            dp[i] = (dp[i - 1] + dp[i - 2]) % M;

        return dp[n];
    }
};

/* 超时 */
class Solution {
public:

    int fib(int n) {
        int M = 1e9 + 7;

        if (n <= 1)
            return n;

        return (fib(n - 1) % M + fib(n - 2) % M) % M;
    }
};
