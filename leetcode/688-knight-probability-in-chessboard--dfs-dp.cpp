



class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        /*
         * 动态规划
         * dp[i][j][k] - 马跳k次停留在位置(i,j)的概率
         * dp[i][j][k] = sum(dp[i + dx][dp[j + dy][k - 1]) / 8
         * dp[i + dx][j + dy][k - 1] - 马跳k - 1次在(i + dx, j + dy)的概率
         * dp[r][c][0] = 1 开始0步时，必在棋盘内
         * 结果为sum(dp[i][j][K]) - 跳K次停留在棋盘内的概率
         */
        int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
        int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
        int rx, cy;
        double ans = 0;
        int i, j, k, l;
        vector<vector<vector<double>>> dp(N, vector<vector<double>> (N, vector<double> (K + 1, 0)));
        dp[r][c][0] = 1.0;

        for (k = 1; k <= K; k++) {
            for (i = 0; i < N; i++) {
                for (j = 0; j < N; j++) {
                    for (l = 0; l < 8; l++) {
                        rx = i + dx[l];
                        cy = j + dy[l];
                        if (rx >= 0 && rx < N && cy >= 0 && cy < N) {
                            dp[rx][cy][k] += dp[i][j][k - 1] / 8.0;
                        }
                    }
                }
            }
        }

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                ans += dp[i][j][K];
            }
        }

        return ans;
    }
};

class Solution {
public:
    double dfs(vector<vector<vector<double>>> &memo, int n, int k, int steps, int r, int c) {
        int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
        int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
        int rx, cy, i;
        double ans = 0;

        if (r < 0 || r >= n || c < 0 || c >= n)
            return 0;
        if (steps == k)
            return 1.0;

        if (memo[r][c][steps])
            return memo[r][c][steps];

        /* r,c可以向8个方向移动 */
        for (i = 0; i < 8; i++) {
            rx = r + dx[i];
            cy = c + dy[i];
            if (rx >= 0 && rx < n && cy >= 0 && cy < n) {
                ans += dfs(memo, n, k, steps + 1, rx, cy);
            }
        }
        ans /= 8;
        memo[r][c][steps] = ans;
        return ans;
    }

    double knightProbability(int N, int K, int r, int c) {
        /* 记忆化搜索 */
        vector<vector<vector<double>>> memo(N, vector<vector<double>> (N, vector<double> (K + 1, 0)));
        return dfs(memo, N, K, 0, r, c);
    }
};
