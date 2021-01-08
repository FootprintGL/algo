

/* 并查集 */
class DSU {
    vector<int> parent;
    vector<int> sz;
    int n;

public:
    DSU(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            sz.push_back(1);
        }
        this->n = n;
    }

    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry)
            return;

        if (sz[rx] > sz[ry]) {
            parent[ry] = rx;
            sz[rx] += sz[ry];
        } else {
            parent[rx] = ry;
            sz[ry] += sz[rx];
        }
    }

    int find(int x) {
        return x == parent[x] ? x : find(parent[x]);
    }

    int rank(int x) {
        return sz[x];
    }

    void dump() {
        for (int i = 0; i < n; i++)
            cout << parent[i] << " ";
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << sz[i] << " ";
        cout << endl;
        cout << endl;
    }
};

void dump(vector<vector<int>> &grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        /*
         * 并查集 - 逆向思维
         * 每次加上一个砖块,并计算有多少额外的砖块因为这个砖块的增加而和网格的顶部直接或间接相连
         * 这样就可以用并查集来解决
         *  1 生成一个并查集, 长度为二维数组压缩为一维数组,最后添加一个虚拟节点，模拟天花板
         *  2 把所有第一行的砖块和天花板合并，这个集合称为天花板集合，所有与这个集合合并的集合就是打掉的砖块
         *  3 把hits中的砖块置0，本来一个大的连通分量，被切成多个小的连通分量
         *  4 逆序遍历hits，依次放回打掉的砖块合并相邻砖块，天花板集合元素增加的个数 - 1记为该次打掉的砖块
         */
        vector<int> ans(hits.size(), 0);

        //dump(grid);
        /* 打掉的砖置-1 */
        for (auto &hit : hits) {
            if (grid[hit[0]][hit[1]] == 1)
                grid[hit[0]][hit[1]] = -1;
        }
        //dump(grid);

        int m = grid.size();
        int n = grid[0].size();
        /* 构建并查集 - 末尾添加一个虚拟节点模拟天花板 */
        DSU dsu(m * n + 1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int id = i * n + j;
                if (grid[i][j] == 1) {
                    if (i == 0)
                        dsu.merge(id, m * n);
                    if (i > 0 && grid[i - 1][j] == 1)
                        dsu.merge(id, (i - 1) * n + j);
                    if (j > 0 && grid[i][j - 1] == 1)
                        dsu.merge(id, id - 1);
                }
            }
        }

        //dsu.dump();

        for (int i = hits.size() - 1; i >= 0; i--) {
            /* 逆序遍历 - 时光倒流 */
            int x = hits[i][0];
            int y = hits[i][1];
            if(grid[x][y] == -1){
                /* 保存当前天花板集合元素个数 */
                int prev = dsu.rank(dsu.find(m * n));

                /* 向四个方向合并 */
                grid[x][y] = 1;

                //cout << x << " " << y << " " << prev << endl;
                //dump(grid);

                if (x > 0 && grid[x - 1][y] == 1)
                    dsu.merge(x * n + y, (x - 1) * n + y);
                //dsu.dump();
                if (x < m - 1 && grid[x + 1][y] == 1)
                    dsu.merge(x * n + y, (x + 1) * n + y);
                //dsu.dump();
                if (y > 0 && grid[x][y - 1] == 1)
                    dsu.merge(x * n + y, x * n + y - 1);
                //dsu.dump();
                if (y < n - 1 && grid[x][y + 1] == 1)
                    dsu.merge(x * n + y, x * n + y + 1);
                //dsu.dump();
                /* 第一行直接和天花板合并 */
                if (x == 0)
                    dsu.merge(x * n + y, m * n);
                //dsu.dump();

                /* {x,y}已经和天花板集合连通 */
                if (dsu.find(x * n + y) == dsu.find(m * n)) {
                    ans[i] = dsu.rank(dsu.find(m * n)) - prev - 1;
                }
            }
        }

        return ans;
    }
};
