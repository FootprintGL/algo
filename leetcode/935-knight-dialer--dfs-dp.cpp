class Solution {
public:
    int M = 1000000000 + 7;
    int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
    int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

    int knightDialer(int n) {
        vector<vector<vector<int>>> dp (4, vector<vector<int>> (3, vector<int> (n, 0)));
        int ans = 0;
        int r, c;
        int i, j, k, l;
        
        /* 
         * 动态规划
         * dp[i][j][k] - 第k步跳到(i, j)的拨号方法数
         * dp[i][j][k] = sum(dp[i + dx[l]][j + dy[l]][k - 1])
         * 边界状态 - dp[i][j][0] = 1, (i,j)是数字键
         */

        /* 从0，1，2，3，4，5，6，7，8，9开始起跳 */
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 3; j++) {
                if ((i == 3 && j == 0) || (i == 3 && j == 2)) {
                    continue;
                }
                dp[i][j][0] = 1;
            }
        }

        for (k = 1; k < n; k++) {
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 3; j++) {
                    if ((i == 3 && j == 0) || (i == 3 && j == 2)) {
                        continue;
                    }
                    for (l = 0; l < 8; l++) {
                        r = i + dx[l];
                        c = j + dy[l];
                        if (r < 0 || r > 3 || c < 0 || c > 2 || (r == 3 && c == 0) || (r == 3 && c == 2))
                            continue;
                        dp[i][j][k] = (dp[i][j][k] + dp[r][c][k - 1]) % M;
                    }
                }
            }
        }

        for (i = 0; i < 4; i++) {
            for (j = 0; j < 3; j++) {
                if ((i == 3 && j == 0) || (i == 3 && j == 2)) {
                    continue;
                }
                ans = (ans + dp[i][j][n - 1]) % M;
            }
        }

/*
        for (k = 0; k < n; k++) {
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 3; j++) {
                    cout << dp[i][j][k] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
*/
        return ans;
    }
};


class Solution {
public:
    int M = 1000000000 + 7;
    int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
    int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

    /* dfs - 记忆化搜索 */
    int dfs(vector<vector<vector<int>>> &dp, int r, int c, int n, int steps) {
        //cout << r << " " << c << " " << steps << endl;

        /* 没有跳到数字上，返回0 */
        if (r < 2 || r > 5 || c < 2 || c > 4 || (r == 5 && c == 2) || (r == 5 && c == 4))
            return 0;

        /* 跳完n - 1步 - 新增一种拨号方式 */
        if (steps == n - 1) {
            return 1;
        }

        /* 如果已经保存，直接返回 */
        if (dp[r][c][steps] != -1) {
            return dp[r][c][steps];
        }

        int sum = 0;
        int rx, cy, k;

        /* 下一步可以向8个方向跳 */
        for (k = 0; k < 8; k++) {
            rx = r + dx[k];
            cy = c + dy[k];
            sum = (sum + dfs(dp, rx, cy, n, steps + 1)) % M;
        }

        /* 保存结果 */
        dp[r][c][steps] = sum;
        return sum;
    }

    int knightDialer(int n) {
        vector<vector<vector<int>>> dp (4 + 4, vector<vector<int>> (3 + 4, vector<int> (n, -1)));
        int ans = 0;
        int i, j;

        /* 从0，1，2，3，4，5，6，7，8，9开始起跳 */
        for (i = 2; i <= 5; i++) {
            for (j = 2; j <= 4; j++) {
                if ((i == 5 && j == 2) || (i == 5 && j == 4)) {
                    continue;
                }
                ans = (ans + dfs(dp, i, j, n, 0)) % M;
            }
        }

        return ans;
    }
};
