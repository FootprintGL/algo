
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int M = 1000000000 + 7;

    int dfs(vector<vector<vector<int>>> &dp, int m, int n, int N, int steps, int r, int c) {
        if (r < 0 || r >= m || c <0 || c >= n)
            return 1;

        if (steps == N)
            return 0;

        /* dp[r][c][steps]缓存的值可能等于0，初始值设为-1 */
        if (dp[r][c][steps] != -1) {
            return dp[r][c][steps];
        }

        int rx, cy, i, tmp, sum = 0;

        for (i = 0; i < 4; i++) {
            rx = r + dx[i];
            cy = c + dy[i];
            tmp = dfs(dp, m, n, N, steps + 1, rx, cy) % M;
            sum = (sum + tmp) % M;
        }
        dp[r][c][steps] = sum;

        return sum;
    }
    int findPaths(int m, int n, int N, int i, int j) {
        /* 记忆化搜索 */
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int> (N + 1, -1)));
        return dfs(dp, m, n, N, 0, i, j);
    }
};


class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        /*
         * 动态规划
         * dp[r][c][k] - 从(r,c)出发，第k步出界的路径总数
         * dp[r][c][k] = dp[r - 1][c][k - 1] + dp[r][c - 1][k - 1] + dp[r + 1][c] + dp[r][c + 1]
         * 边界状态
         * dp[r][c][0] - 最外圈为1
         * 结果为sum(dp[i][j][k]), k = 1 -> N
         * 四周加一圈0以简化处理
         */
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int M = 1000000000 + 7;
        vector<vector<vector<int>>> dp(m + 2, vector<vector<int>>(n + 2, vector<int> (N + 1, 0)));
        int r, c, k, l, sum = 0;
        int rx, cy;

        /* 四周边界初始化为1 */
        for (r = 0; r <= m + 1; r++ ) {
            dp[r][0][0] = 1;
            dp[r][n + 1][0] = 1;
        }
        for (c = 0; c <= n + 1; c++) {
            dp[0][c][0] = 1;
            dp[m + 1][c][0] = 1;
        }
/*
        for (r = 0; r < m + 2; r++) {
            for (c = 0; c < n + 2; c++)
                cout << dp[r][c][0] << " ";
            cout << endl;
        }
*/
        for (k = 1; k <= N; k++) {
            for (r = 1; r <= m; r++) {
                for (c = 1; c <= n; c++) {
                    for (l = 0; l < 4; l++) {
                        rx = r + dx[l];
                        cy = c + dy[l];
                        dp[r][c][k] = (dp[r][c][k] + dp[rx][cy][k - 1]) % M;
                    }
                }
            }
        }
/*
        for (k = 0; k <= N; k++) {
            for (r = 0; r < m + 2; r++) {
                for (c = 0; c < n + 2; c++)
                    cout << dp[r][c][k] << " ";
                cout << endl;
            }
            cout << endl;
        }
*/
        for (k = 1; k <= N; k++)
            sum = (sum + dp[i + 1][j + 1][k]) % M;

        return sum;
    }
};
