

struct Edge {
    int x;
    int y;
    int h;

    Edge(int i, int j, int h) : x(i), y(j), h(h) {}
    bool operator < (const Edge& other) const {
        return this->h > other.h;
    }
};

class DSU {
    vector<int> parent;
    int count;

public:
    DSU(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
        count = n;
    }

    int find(int x) {
        return x == parent[x] ? x : find(parent[x]);
    }

    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        //cout << x << " " << y << " " << rx << " " << ry << endl;
        if (rx != ry)
            parent[rx] = ry;
    }

    bool isconnected(int x, int y) {
        return (find(x) == find(y));
    }

    void dump() {
        for (int i = 0; i < count; i++)
            cout << parent[i] << " ";
        cout << endl;
    }
};

class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};

public:
    int swimInWater(vector<vector<int>>& grid) {
        /*
         * 并查集 + 优先队列
         * 每个位置水位从低到高排序(优先队列)，依次出队直到左上右下连通为止
         * 1 先把所有点坐标和高度入队，h升序
         * 2 遍历每个时间点,并将在高度和时间点相等时出队列，表示当次新增的点，将新增的点与周边
         * 能走通的点关联起 - 并查集
         * 3 每个时间点，所有关联关系建立以后,检查起点和终点是否在一个集合，如果在一个集合的话
         * 说明当前出队的点已经有一条可行路径
         */
        priority_queue<Edge> pq;
        int n = grid.size();
        DSU dsu(n * n);

        /* 将每个位置信息放入队列 */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pq.push({i, j, grid[i][j]});
            }
        }
        //cout << pq.top().h << " " << pq.size() << endl;

        /* 根据数据规模，t = 0 ~ N - 1 */
        for (int t = 0; t < n * n; t++) {
            while (!pq.empty() && pq.top().h == t) {
                Edge cur = pq.top();
                pq.pop();
                int x = cur.x;
                int y = cur.y;
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] <= t) {
                        //cout << t << " " << x << " " << y << " " << nx << " " << ny << " " << grid[nx][ny]<< endl;
                        dsu.merge(x * n + y, nx * n + ny);
                        //dsu.dump();
                        if (dsu.isconnected(0, n * n - 1))
                            return t;
                    }
                }
            }
        }

        return n * n - 1;
    }
};
