
class Solution {
public:
    int cuttingRope(int n) {
        /*
         * 动态规划
         * dp[i] - i能拆分的最大乘积
         * dp[i] = max{(i - j) * j, dp[i - j] * j}，j = 0 -> i - 1
         *      1. 拆分成j, i - j
         *      2. i - j继续拆分
         */
        vector<int> dp(n + 1, 0);
        int i, j;

        dp[1] = 1;
        for (i = 2; i <= n; i++) {
            for (j = 1; j < i; j++) {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }

        return dp[n];
    }
};
