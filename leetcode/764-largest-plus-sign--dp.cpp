
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        /*
         * 动态规划
         * dp[i][j][k] - (i,j)四个方向上1的个数,0-左，1-上，2-右，3-下
         * 如果(i,j)位置为1，(i,j)可形成min(dp[i][j][k])阶的加号标志
         * 上下左右方向没有关联, 只保存最小的就可以了
         * 如果(i,j)位置为0，(i, j)无法形成加号标志
         * 边计算边更新最大阶加号标志
         */
        if (mines.size() == 0)
            return (N - 1) / 2 + 1;

        vector<vector<int>> mat(N, vector<int>(N, N));
        int left, right, up, down;
        int i, j, k, ans = 0;

        for (i = 0; i < mines.size(); i++)
            mat[mines[i][0]][mines[i][1]] = 0;

        /* 计算(i,j)上min(dp[i][j][0,1,2,3]) */
        for (i = 0; i < N; i++) {
            left = 0;
            right = 0;
            up = 0;
            down = 0;
            for (j = 0, k = N - 1; j < N; j++, k--) {
                /* i行左边 */
                left = (mat[i][j] == 0 ? 0 : left + 1);
                mat[i][j] = min(mat[i][j], left);

                /* i行右边 */
                right = (mat[i][k] == 0 ? 0 : right + 1);
                mat[i][k] = min(mat[i][k], right);

                /* i列上面 */
                up = (mat[j][i] == 0 ? 0 : up + 1);
                mat[j][i] = min(mat[j][i], up);

                /* i列下面 */
                down = (mat[k][i] == 0 ? 0 : down + 1);
                mat[k][i] = min(mat[k][i], down);
            }
        }

        /* 寻找最大加号标记的阶数 */
        for (i = N - 1; i >= 0; i--) {
            for (j = N - 1; j >= 0; j--) {
                if (mat[i][j] > ans)
                    ans = mat[i][j];
            }
        }

        return ans;
    }
};


/* 改为4二维数组dp能通过，可能三维寻址更耗时 */
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> grid(N, vector<int>(N, 1));
        for (auto& mine : mines) {
            int i = mine[0];
            int j = mine[1];
            grid[i][j] = 0;
        }
        vector<vector<int>> left(N, vector<int>(N));
        vector<vector<int>> up(N, vector<int>(N));
        vector<vector<int>> right(N, vector<int>(N));
        vector<vector<int>> down(N, vector<int>(N));
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0;j < N; j++) {
                if (grid[i][j] == 0) continue;
                left[i][j] = 1;
                if (j > 0) left[i][j] += left[i][j - 1];
                up[i][j] = 1;
                if (i > 0) up[i][j] += up[i - 1][j];
                else up[i][j] = 1;
            }
        }
        for (int i = N - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                if (grid[i][j] == 0) continue;
                if (j < N - 1) right[i][j] = right[i][j + 1] + 1;
                else right[i][j] = 1;
                if (i < N - 1) down[i][j] = down[i + 1][j] + 1;
                else down[i][j] = 1;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int l1 = min(left[i][j], up[i][j]);
                int l2 = min(right[i][j], down[i][j]);
                ans = max(ans, min(l1, l2));
            }
        }
        return ans;
    }
};


/* 三维dp超时 */
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        /*
         * 动态规划
         * dp[i][j][k] - (i,j)四个方向上1的个数,0-左，1-上，2-右，3-下
         * 如果(i,j)位置为1，(i,j)可形成min(dp[i][j][k])阶的加号标志
         * 如果(i,j)位置为0，(i, j)无法形成加号标志
         * 边计算边更新最大阶加号标志
         */
        vector<vector<int>> mat(N, vector<int>(N, 1));
        vector<vector<vector<int>>> dp(N + 2, vector<vector<int>> ( N + 2, vector<int> (4, 0)));

        int i, j, t1, t2, ans = 0;

        if (mines.size() == 0)
            return (N - 1) / 2 + 1;

        for (i = 0; i < mines.size(); i++)
            mat[mines[i][0]][mines[i][1]] = 0;

        /* 计算左边和上边 */
        for (i = 1; i <= N; i++) {
            for (j = 1; j <= N; j++) {
                if (mat[i - 1][j - 1] == 1) {
                    dp[i][j][0] = dp[i][j - 1][0] + 1;
                    dp[i][j][1] = dp[i - 1][j][1] + 1;
                }
            }
        }

        /* 计算右边和下边并更新最大加号标记的阶数 */
        for (i = N; i >= 1; i--) {
            for (j = N; j >= 1; j--) {
                if (mat[i - 1][j - 1] == 1) {
                    dp[i][j][2] = dp[i][j + 1][2] + 1;
                    dp[i][j][3] = dp[i + 1][j][3] + 1;
                    t1 = min(dp[i][j][0], dp[i][j][1]);
                    t2 = min(dp[i][j][2], dp[i][j][3]);
                    ans = max(ans, min(t1, t2));
                }
            }
        }

        return ans;
    }
};



/* 超时 - O(n^2) - 对于大mines, 查找太费时 */
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        /*
         * 动态规划
         * dp[i][j][k] - (i,j)四个方向上1的个数,0-左，1-上，2-右，3-下
         * 如果(i,j)位置为1，(i,j)可形成min(dp[i][j][k])阶的加号标志
         * 如果(i,j)位置为0，(i, j)无法形成加号标志
         * 边计算边更新最大阶加号标志
         */
        vector<vector<vector<int>>> dp(N + 2, vector<vector<int>> ( N + 2, vector<int> (4, 0)));
        /* unordered_set默认不支持pair做key，需要添加哈希函数 */
        //unordered_set<pair<int, int>> zerotbl;
        /* (i,j) - i * N + j唯一，用它做key将哈希表降到1维 */
        unordered_set<int> zerotbl;
        int i, j, t, ans = 0;

        if (mines.size() == 0)
            return (N - 1) / 2 + 1;

        for (i = 0; i < mines.size(); i++)
            zerotbl.insert(mines[i][0] * N + mines[i][1]);

        /* 计算左边和上边 */
        for (i = 1; i <= N; i++) {
            for (j = 1; j <= N; j++) {
                if (zerotbl.find((i - 1) * N + j - 1) == zerotbl.end()) {
                    dp[i][j][0] = dp[i][j - 1][0] + 1;
                    dp[i][j][1] = dp[i - 1][j][1] + 1;
                }
            }
        }

        /* 计算右边和下边并更新最大加号标记的阶数 */
        for (i = N; i >= 1; i--) {
            for (j = N; j >= 1; j--) {
                if (zerotbl.find((i - 1) * N + j - 1) == zerotbl.end()) {
                    dp[i][j][2] = dp[i][j + 1][2] + 1;
                    dp[i][j][3] = dp[i + 1][j][3] + 1;
                    t = min(dp[i][j][0], dp[i][j][1]);
                    t = min(t, dp[i][j][2]);
                    t = min(t, dp[i][j][3]);
                    if (t > ans)
                        ans = t;
                }
            }
        }

        return ans;
    }
};
