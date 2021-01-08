
/* 并查集 - unionfind set */

class UnionFind {
    vector<int> parent;

public:
    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    void myunion(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty)
            return;
        parent[rootx] = rooty;
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        /* 并查集 - 相邻城市具有传递性，合并后统计root的个数即为省份个数 */
        int n = isConnected.size();
        UnionFind unionfind(n);

        /* 构建并查集 */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isConnected[i][j] == 1)
                    unionfind.myunion(i, j);
            }
        }

        /* 统计根节点的个数 */
        int res = 0;
        for (int i = 0; i < n; i++)
            if (unionfind.find(i) == i)
                res++;

        return res;
    }
};

/* 并查集 - unionfind set */

class UnionFind {
    vector<int> parent;

public:
    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    void myunion(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty)
            return;
        parent[rootx] = rooty;
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        /* 并查集 - 相邻城市具有传递性，合并后统计root的个数即为省份个数 */
        int n = isConnected.size();
        UnionFind unionfind(n);

        /* 构建并查集 */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isConnected[i][j] == 1)
                    unionfind.myunion(i, j);
            }
        }

        /* root放入哈希表统计省份的个数 */
        unordered_set<int> tbl;
        for (int i = 0; i < n; i++)
            tbl.insert(unionfind.find(i));

        return tbl.size();
    }
};
