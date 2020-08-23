

class Solution {
public:
    double soupServings(int N) {
        double ans;

        if (N % 25)
            N = N / 25 + 1;
        else
            N = N / 25;

        /*
         * 动态规划
         * dp[i][j] - A,B分别剩下i,j时所求的概率
         * dp[i][j] = 1 / 4 (dp[i - 4][j] + dp[i - 3][j - 1] + dp[i - 2][j - 2] + dp[i - 1][j - 3]))
         * 边界条件:
         * i <= 0, j <= 0: dp[i][j] = 0.5
         * i <= 0, j > 0: dp[i][j] = 1
         * i > 0, j <= 0: dp[i][j] = 0
         * 结果为dp[N][N]
         * 当N很大时，A一定先分完，所求概率趋向于1，dp[100] - 1已经满足“返回值在 10^-6 的范围将被认为是正确的“
         */
        if (N >= 400)
            return 1.0;

        vector<vector<double>> dp(N + 1, vector<double>(N + 1, 0));
        int a1, a2, a3, a4;
        int b1, b2, b3, b4;
        int i, j;
        dp[0][0] = 0.5;

        for (i = 1; i <= N; i++) {
            dp[i][0] = 0;
            dp[0][i] = 1;
        }

        for (i = 1; i <= N; i++) {
            a1 = i - 4 > 0 ? i - 4 : 0;
            a2 = i - 3 > 0 ? i - 3 : 0;
            a3 = i - 2 > 0 ? i - 2 : 0;
            a4 = i - 1 > 0 ? i - 1 : 0;
            for (j = 1; j <= N; j++) {
                b1 = j;
                b2 = j - 1 > 0 ? j - 1 : 0;
                b3 = j - 2 > 0 ? j - 2 : 0;
                b4 = j - 3 > 0 ? j - 3 : 0;
                dp[i][j] = 0.25 * (dp[a1][b1] + dp[a2][b2] + dp[a3][b3] + dp[a4][b4]);
            }
        }
        //cout << N << " " << dp[N][N] << endl;
        return dp[N][N];
    }
};
