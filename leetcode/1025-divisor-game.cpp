class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> dp(N + 1, false);
        int x;
        int i, j;
        /*
         * 动态规划
         * dp[i]表示黑板上为i是A能否赢得游戏, N等于1时A会输，N等于2时A会赢
         * 所有0～i内i公约数j，只要有一个dp[i - x]是false，则dp[i]为true
         * 返回dp[N]
         */
        dp[1] = false;
        dp[2] = true;
        for (i = 3; i <= N; i++) {
            for (j = 1; j < i; j++) {
                if (i % j == 0 && !dp[i - j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[N];
    }
};
