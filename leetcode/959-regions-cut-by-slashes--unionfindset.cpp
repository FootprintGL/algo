


class DSU {
    vector<int> parent;

public:
    DSU(int n) {
        for (int i = 0; i < n; i++)
            parent.push_back(i);
    }

    void merge(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            parent[rootx] = rooty;
        }
    }

    int find(int x) {
        return x == parent[x] ? x : find(parent[x]);
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        /*
         * 并查集
         * 通过\/将区域分成4块，然后顺时针标记划分为0(上)，1(右)，2(下)，3(左)
         *      如果碰到/，将0-3合并，1-2合并
         *      如果碰到\，将0-1合并，2-3合并
         *      如果碰到空格，将1，2，3，4合并
         * 最后使每个小组合和接邻四方归并
         *      左边格子的1和右边格子的3
         *      上边格子的2和下边格子的0
         */
        int n = grid.size();
        DSU dsu(4 * n * n);

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int root = 4 * (r * n + c);
                char val = grid[r][c];
                if (val != '\\') {
                    /* /或空格 */
                    dsu.merge(root, root + 3);
                    dsu.merge(root + 1, root + 2);
                }
                if (val != '/') {
                    /* \或空格 */
                    dsu.merge(root, root + 1);
                    dsu.merge(root + 2, root + 3);
                }
                if (r + 1 < n) {
                    /* 向下归并 */
                    dsu.merge(root + 2, root + 4 * n);
                }
                if (c + 1 < n) {
                    /* 向右归并 */
                    dsu.merge(root + 1, root + 4 + 3);
                }
            }
        }

        /* 统计连通区域个数 */
        int ans = 0;
        for (int x = 0; x < 4 * n * n; x++)
            if (dsu.find(x) == x)
                ans++;

        return ans;
    }
};
