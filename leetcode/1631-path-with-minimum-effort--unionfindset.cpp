

class Edge {
public:
    int x;
    int y;
    int val;

    Edge(int x, int y, int val) {
        this->x = x;
        this->y = y;
        this->val = val;
    }
};

class DSU {
    vector<int> parent;

public:
    DSU(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    int find(int x) {
        return x == parent[x] ? x : find(parent[x]);
    }

    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry)
            parent[rx] = ry;
    }

    bool isconnected(int x, int y) {
        return (find(x) == find(y));
    }
};

bool compare(Edge &e1, Edge &e2) {
    return e1.val < e2.val;
}

class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    int m, n;

    bool inarea(int r, int c) {
        return (r >= 0 && r < m && c >= 0 && c < n);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        /*
         * 并查集
         * 将所有的边按从小到大排列并依次放入并查集，直到左上角和右下角联通为止
         */
        m = heights.size();
        n = heights[0].size();

        vector<Edge> edges;

        /* 相邻位置连接成边 */
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int id = i * n + j;
                if (i > 0)
                    edges.push_back({id - n, id, abs(heights[i][j] - heights[i - 1][j])});
                if (j > 0)
                    edges.push_back({id - 1, id, abs(heights[i][j] - heights[i][j - 1])});
            }
        }

        /* 按边长排序 */
        sort(edges.begin(), edges.end(), compare);

        /* 依次合并直到左上右下连通 */
        DSU dsu(m * n);
        for (auto &edge : edges) {
            dsu.merge(edge.x, edge.y);
            if (dsu.isconnected(0, m * n - 1))
                return edge.val;
        }

        return 0;
    }
};



class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    int m, n;

    bool inarea(int r, int c) {
        return (r >= 0 && r < m && c >= 0 && c < n);
    }

    /* 检查体力值为val能否到达终点 */
    bool bfs(vector<vector<int>> &heights, int val) {
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        queue<pair<int, int>> qu;
        qu.push({0, 0});
        vis[0][0] = true;

        while (!qu.empty()) {
            auto cur = qu.front();
            int r = cur.first, c = cur.second;
            //cout << r << " " << c << " " << m << " " << n << endl;
            if (r == m - 1 && c == n - 1)
                return true;

            qu.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                //cout << nr << " " << nc << " " << heights[r][c] << " " << heights[0][1] << " " << val << endl;
                /* 判断(r, c) --> (nr, nc)的距离是否比当前距离小，如果是，该点有效 */
                if (inarea(nr, nc) && !vis[nr][nc] && abs(heights[nr][nc] - heights[r][c]) <= val) {
                    //cout << nr << " - " << nc << " " << heights[r][c] << " " << heights[nr][nc] << endl;
                    qu.push({nr, nc});
                    vis[nr][nc] = true;
                }
            }
        }

        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        /*
         * BFS + 二分
         * 题目要求找路径，使得消耗体力值最小,可以转换成，给定一个固定体力值，是否能找到一条有效路径
         * 根据题意给出的数据规模，max取值为[1, 100000], 不断缩小这个区间，找到一条最小消耗值的路径
         */
        m = heights.size();
        n = heights[0].size();
        int left = 0, right = 1000000;
        //int left = 999998, right = 1000000;
        /* 二分搜索 */
        while (left < right) {
            int mid = left + (right - left) / 2;
            //cout << left << " " << right << " " << mid << endl;
            if (bfs(heights, mid))
                right = mid;
            else
                left = mid + 1;
            //cout << left << " " << right << endl;
        }

        return left;
    }
};
