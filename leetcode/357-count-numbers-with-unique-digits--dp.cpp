

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 10;
        /*
         * 动态规划
         * dp[i] -> 长度为i位的各位数字都不同的数字x的个数
         * dp[i] = dp[i - 1] * (10 - (i - 1)), 一共10个数字，已经用了i - 1个
         * 还剩下(10 - (i - 1))个可供选择
         * 边界条件: dp[0] = 1, dp[1] = 9, 第1位不能为0
         */
        vector<int> dp(n + 1, 0);
        int ans;
        dp[0] = 1;
        dp[1] = 9;
        ans = dp[0] + dp[1];
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] * (10 - (i - 1));
            ans += dp[i];
        }

        return ans;
    }
};
