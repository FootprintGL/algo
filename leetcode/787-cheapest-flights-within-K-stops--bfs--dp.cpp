
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        /*
         * 动态规划
         * dp[i][j] - 通过j次中转到达i的最小话费
         * dp[i][j] = min{dp[s]][j - 1] + price(s->i)}, 存在s->i的航班
         * dp[n][K + 2] - 一共可以飞 K + 1次
         * dp[src][j] = 0, j = 0 -> K + 1
         * 结果为dp[dst][K + 1]
         */
        int m = flights.size();
        if (m == 0)
            return dst == src ? 0 : -1;

        vector<vector<int>> dp(n, vector<int>(K + 2, INT_MAX));
        int i, j;

        for (i = 0; i < K + 2; i++)
            dp[src][i] = 0;

        for (j = 1; j <= K + 1; j++) {
            for (auto &flight : flights) {
                if (dp[flight[0]][j - 1] != INT_MAX) {
                    dp[flight[1]][j] = min(dp[flight[1]][j], dp[flight[0]][j - 1] + flight[2]);
                }
            }
        }
/*
        cout << n << " " << K << endl;
        for (i = 0; i < n; i++) {
            for (j = 0; j < K + 2; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
*/
        return dp[dst][K + 1] == INT_MAX ? -1 : dp[dst][K + 1];
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int m = flights.size();
        if (m == 0)
            return src == dst ? 0 : -1;

        vector<vector<pair<int, int>>> adj(n);
        queue<pair<int, int>>qu;
        pair<int, int> cur;
        int ans = INT_MAX, size;
        bool found = false;
        int i, j;

        /* 建立链接表 */
        for (i = 0; i < m; i++)
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});

        /* BFS */
        qu.push({src, 0});

        while (!qu.empty()) {
            size = qu.size();
            for (i = 0; i < size; i++) {
                cur = qu.front();
                qu.pop();
                for (j = 0; j < adj[cur.first].size(); j++) {
                    if (adj[cur.first][j].first == dst) {
                        /* 找到dst - 从dst继续搜索没有意义，不需要入队 */
                        found = true;
                        ans = min(ans, cur.second + adj[cur.first][j].second);
                        continue;
                    }
                    if (cur.second + adj[cur.first][j].second >= ans)
                        /* 如果已经超过目前最低花费，不再继续搜索，不需要入队 */
                        continue;
                    qu.push({adj[cur.first][j].first, cur.second + adj[cur.first][j].second});
                }
            }
            if (--K < 0)
                break;
        }

        return found ? ans : -1;
    }
};
