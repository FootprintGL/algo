class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n, 0);
        int i;

        /* 特殊情况处理 */
        if (n == 1)
            return 1;

        dp[0] = 1;
        dp[1] = 2;
        /* 动态规划 */
        for (i = 2; i < n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        
        return dp[n - 1];
    }
};


/* 空间优化 */
class Solution {
public:
    int climbStairs(int n) {
        int step, step1, step2;
        int i;

        /* 特殊情况处理 */
        if (n == 1)
            return 1;

        step1 = 1;
        step = step2 = 2;
        /* 动态规划 */
        for (i = 2; i < n; i++) {
            step = step1 + step2;
            step1 = step2;
            step2 = step;
        }

        return step;
    }
};
