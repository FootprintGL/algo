
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1, false);
        int i, j;

        /*
         * 动态规划
         * dp[i]剩下i个石子，Alice能否赢得比赛
         * dp[i] = dp[i - x * x], x = 1 -> x (x * x <= i)
         * 返回dp[n]
         */
        dp[1] = true;
        for (i = 2; i <= n; i++) {
            for (j = 1; j * j <= i; j++) {
                if (dp[i - j * j] == false) {
                    dp[i] = true;
                    break;
                }
                dp[i] = false;
            }
        }
/*
        cout << "dp: " << endl;
        for (i = 0; i <= n; i++)
            cout << dp[i] << " ";
        cout << endl;
*/
        return dp[n];
    }
};
