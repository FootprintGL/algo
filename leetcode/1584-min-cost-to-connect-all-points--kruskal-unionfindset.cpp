

struct Edge {
    int x;
    int y;
    int len;

    Edge(int &x, int &y, int &len) {
        this->x = x;
        this->y = y;
        this->len = len;
    }

    bool operator<(Edge &e) {
        return len < e.len;
    }
};

class DSU {
    vector<int> parent, rank;
    int n;
public:
    DSU(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            rank.push_back(1);
        }
    }

    int find(int x) {
        return x == parent[x] ? x : find(parent[x]);
    }

    bool merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry)
            return false;
        if (rank[rx] < rank[ry]) {
            parent[ry] = rx;
            rank[rx] += rank[ry];
        } else {
            parent[rx] = ry;
            rank[ry] += rank[rx];
        }
        n--;
        return true;
    }

    int getnum() {
        return n;
    }
};

class Solution {
public:
    int edgelength(vector<int> &p1, vector<int> &p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        /*
         * 最小生成树 - Kruskal算法
         * 根据题意,我们得到一张由n个节点的完全图，任意两点之间的距离均为曼哈顿距离，现在需要截取
         * 一个子图，恰满足子图的任意两点之间有且只有一条简单路径，且所有边的总权值之和尽可能小
         * 能满足任意两点之间有且仅有一条简单路径只有树，且这棵树包含n个节点，这棵树为为给定图的
         * 生成树，其中总权值最小的树，称为最小生成树 - 经典算法 - Kruskal算法
         * Kruskal本质上是贪心算法，该算法由小到大加入边，直到成树
         *      1 将图G所有边，从小到大排序
         *      2 初始化空图G',从前往后扫描排序后的边，如果扫描到的边e在G'中链接了两个不同的连通块，则放入G'中
         *      3 最后得到的图G'就是G的最小生成树
         */
        int res = 0;
        int n = points.size();
        DSU dsu(n);

        /* 计算任意两点的边长 */
        vector<Edge> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = edgelength(points[i], points[j]);
                //cout << len << endl;
                edges.emplace_back(i, j, len);
            }
        }
        //cout << edges.size() << endl << endl;

        /* 按边长排序 */
        sort(edges.begin(), edges.end());
        //cout << edges.size() << endl;

        /* 放入并查集 */
        for (auto &e : edges) {
            //cout << e.len << endl;
            if (dsu.merge(e.x, e.y)) {
                //cout << e.len << endl;
                res += e.len;
                if (dsu.getnum() == 1)
                /* 只剩一个集合 - 全部连通 */
                    break;
            }
        }

        return res;
    }
};
