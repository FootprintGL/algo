

class Solution {
public:
    vector<int> p;

    /* 并查集 - 初始化 */
    void init(int n) {
        for (int i = 0; i <= n; i++)
            p.push_back(i);
    }

    /* 并查集 - 合并 */
    bool union_root(int u, int v) {
        int r1 = find_root(u);
        int r2 = find_root(v);
        if (r1 == r2)
        /* 有环 */
            return false;
        p[v] = r1;
        return true;
    }

    /* 并查集 - 查找 */
    int find_root(int u) {
        while (p[u] != u) {
            u = p[u];
        }
        return u;
    }

    /* 搜索入度为2的节点，返回构成的两条边 */
    vector<int> find2indegree(vector<vector<int>> &edges) {
        vector<int> res;
        int n = edges.size();
        vector<int> indegree(n + 1, 0);
        int u, v;
        bool found = false;

        /* 找入度为2的点 */
        for (int i = 0; i < n; i++) {
            v = edges[i][1];
            indegree[v]++;
            if (indegree[v] == 2) {
                found = true;
                break;
            }
        }

        if (found) {
            /* 找形成入度为2的两条边 */
            for (int i = 0; i < n; i++) {
                if (edges[i][1] == v)
                    res.push_back(i);
            }
        }

        return res;
    }

    /* 删除边e看能否成树 */
    bool istreeremoveedge(vector<vector<int>> &edges, int n, int e) {
        init(n);

        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (i == e)
            /* 去掉边e */
                continue;

            if (!union_root(u, v))
            /* 找到环，不能成树 */
                return false;
        }

        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        /*
         * 多一条附加边会有2种情况
         * 1. 附加边指向根节点，形成环，删除环上任意一条边都能成树，题目要求返回最后出现的
         * 2. 附加边指向非根节点，会出现一个入度为2的节点，必须移除一条
         *      a. 如果2条边都在环上，移除任意一条都可以，返回后面的
         *      b. 如果有一条不在环上，只能移除环上的边方能成树
         */
        int n = edges.size();
        vector<int> res = find2indegree(edges);
        if (res.size()) {
            //cout << "case 2: " << res[0] << " " << res[1] << endl;
            /* case 2: 找到构成入度为2的边 */
            if (istreeremoveedge(edges, n, res[1])) {
                return edges[res[1]];
            } else {
                return edges[res[0]];
            }
        }
        //cout << "case 1" << endl;
        /* case 1: 附加边指向根节点，存在环 */
        init(n);
        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (!union_root(u, v)) {
                /* 找到环，{u, v}为最后的附加边 */
                res.push_back(u);
                res.push_back(v);
                break;
            }
        }

        return res;
    }
};
