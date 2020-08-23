

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int m, n;

    /* {x, y}在地图内 */
    bool inbound(int x, int y, vector<string> &maze) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    /* BFS - 计算从位置(x, y)开始到其他位置的最小距离 */
    vector<vector<int>> bfs(int x, int y, vector<string> &maze) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        queue<pair<int, int>> qu;
        pair<int, int> pos;
        int i, j;

        qu.push({x, y});
        res[x][y] = 0;
        while (!qu.empty()) {
            pos = qu.front();
            qu.pop();
            for (j = 0; j < 4; j++) {
                int nx = pos.first + dx[j];
                int ny = pos.second + dy[j];
                if (inbound(nx, ny, maze) &&
                    res[nx][ny] == -1 &&
                    maze[nx][ny] != '#') {
                    qu.push({nx, ny});
                    res[nx][ny] = res[pos.first][pos.second] + 1;
                }
            }
        }

        return res;
    }

    int minimalSteps(vector<string>& maze) {
        m = maze.size();
        n = maze[0].size();
        vector<pair<int, int>> button;
        vector<pair<int, int>> stones;
        pair<int, int> start;
        pair<int, int> target;
        int i, j, k;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (maze[i][j] == 'S') {
                    start.first = i;
                    start.second = j;
                } else if (maze[i][j] == 'T') {
                    target.first = i;
                    target.second = j;
                } else if (maze[i][j] == 'M') {
                    button.push_back({i, j});
                } else if (maze[i][j] == 'O') {
                    stones.push_back({i, j});
                }
            }
        }

        vector<vector<int>> start_dist = bfs(start.first, start.second, maze);
        int bn = button.size(), sn = stones.size();

        /* 没有机关 */
        if (bn == 0)
            return start_dist[target.first][target.second];

        /* 机关到各个石头堆/开始位置/终点位置的最小步数 */
        vector<vector<int>> dist(bn, vector<int>(bn + 2, -1));
        vector<vector<vector<int>>> dd(bn);

        for (i = 0; i < bn; i++) {
            dd[i] = bfs(button[i].first, button[i].second, maze);
            /* 机关i到终点 - 不需要经过石头堆 */
            dist[i][bn + 1] = dd[i][target.first][target.second];
        }

        for (i = 0; i < bn; i++) {
            /* Mi经过stones到start的最小步数 */
            int tmp = -1;
            for (j = 0; j < sn; j++) {
                if (dd[i][stones[j].first][stones[j].second] != -1 &&
                    start_dist[stones[j].first][stones[j].second] != -1)
                    if (tmp == -1 ||
                        tmp > dd[i][stones[j].first][stones[j].second] + start_dist[stones[j].first][stones[j].second]) {
                            tmp = dd[i][stones[j].first][stones[j].second] + start_dist[stones[j].first][stones[j].second];
                        }
            }
            /* Mi经过stones到start的最小步数 */
            dist[i][bn] = tmp;

            /* Mi经过stones到Mj的最小步数 */
            for (j = i + 1; j < bn; j++) {
                int tmp = -1;
                for (k = 0; k < sn; k++) {
                    if (dd[i][stones[k].first][stones[k].second] != -1 &&
                        dd[j][stones[k].first][stones[k].second] != -1)
                        if (tmp == -1 ||
                            tmp > dd[i][stones[k].first][stones[k].second] + dd[j][stones[k].first][stones[k].second])
                            tmp = dd[i][stones[k].first][stones[k].second] + dd[j][stones[k].first][stones[k].second];
                }
                dist[i][j] = tmp;
                dist[j][i] = tmp;
            }
        }

        /* 无法顺利到达终点位置 */
        for (i = 0; i < bn; i++) {
            /* 无法从S经过石头到达所有机关，或无法从机关到达终点 */
            if (dist[i][bn] == -1 || dist[i][bn + 1] == -1)
                return -1;
        }

        /*
         * 动态规划
         * dp[mask][i] - 当前在第i个机关M出，状态为mask的最小步数
         * dp[mask | 2 ^ j][j] = min {dp[mask][i] + dist[i][j]}
         * mask的第i位为1表示第i个机关已触发，为0表示还没有触发
         * 每个mask表达两个集合，一个已触发集合和一个未触发集合
         */
        vector<vector<int>> dp(1 << bn, vector<int>(bn, -1));

        /* 边界条件 - start经过石头堆stones到Mi */
        for (i = 0; i < bn; i++) {
            dp[1 << i][i] = dist[i][bn];
        }

        for (int mask = 1; mask < (1 << bn); mask++) {
            for (i = 0; i < bn; i++) {
                /* 当前dp有效 */
                if (mask & 1 << i) {
                    for (j = 0; j < bn; j++) {
                        /* j不再mask里 */
                        if (!(mask & 1 << j)) {
                            if (dp[mask | 1 << j][j] == -1 ||
                                dp[mask | 1 << j][j] > dp[mask][i] + dist[i][j])
                            dp[mask | 1 << j][j] = dp[mask][i] + dist[i][j];
                        }
                    }
                }
            }
        }

        int res = -1;
        int finalmask = (1 << bn) - 1;
        for (i = 0; i < bn; i++) {
            if (res == -1 ||
                res > dp[finalmask][i] + dist[i][bn + 1])
                res = dp[finalmask][i] + dist[i][bn + 1];
        }

        return res;
    }
};
