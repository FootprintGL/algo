





class Solution {
public:

    void dump(vector<vector<int>> &graph, int N) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                //cout << i << " " << j << " " << graph[i][j] << endl;
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        /* 最短路径 - Dijkstra - 迪克斯特拉算法 */
        const int DIS_MAX = 1000000;
        vector<vector<int>> graph(N + 1, vector<int> (N + 1, DIS_MAX));

        /* 邻接矩阵 */
        for (auto &t : times)
            graph[t[0]][t[1]] = t[2];

        for (int i = 1; i <= N; i++)
            graph[i][i] = 0;

        /* first 目的定点，second 距离 */
        using Pair = pair<int, int>;
        /* 最小堆 */
        priority_queue<Pair, vector<Pair>, greater<Pair>> qu;
        /* 入队 */
        for (int i = 1; i <= N; i++) {
            if ((i != K) && graph[K][i] < DIS_MAX)
                qu.push({i, graph[K][i]});
        }

        /* BFS */
        while (!qu.empty()) {
            /* cur为链接访问过的和未访问过的最小边 */
            Pair cur = qu.top();
            qu.pop();
            //dump(graph, N);
            for (int i = 1; i <= N; i++) {
                //cout << cur.first << " " << cur.second << " " << graph[cur.first][i] << " " << graph[K][i] << endl;
                if (graph[cur.first][i] + cur.second < graph[K][i]) {
                    /* 遍历一遍所有以cur.first为起点的边，做relax并入队 */
                    graph[K][i] = graph[cur.first][i] + cur.second;
                    qu.push({i, graph[K][i]});
                }
            }
        }

        /* 求K到各顶点的最大值 */
        int res = -1;
        for (int i = 1; i <= N; i++) {
            res = max(res, graph[K][i]);
        }

        return res == DIS_MAX ? -1 : res;
    }
};
