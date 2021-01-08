

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
        n--;
    }

    int find(int x) {
        return x == parent[x] ? x : find(parent[x]);
    }

    int rank(int x) {
        return sz[x];
    }

    int getcount() {
        return n;
    }

    bool isconnected(int x, int y) {
        return (find(x) == find(y));
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


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        /*
         * 并查集
         * n个点需要n - 1条边才能连通，优先考虑type3的边
         *
         *
         */
        DSU dsu1(n);
        DSU dsu2(n);
        DSU dsu3(n);
        int cnt1 = 0, cnt2 = 0, cnt3 = 0, ret = 0;

        for (int i = 0; i < edges.size(); i++) {
            int type = edges[i][0];
            /* 下标从0开始 */
            int start = edges[i][1] - 1;
            int end = edges[i][2] - 1;
            if (type == 1)
                cnt1++;
            if (type == 2)
                cnt2++;
            if (type == 3)
                cnt3++;

            if (type ==1 || type == 3)
                dsu1.merge(start, end);

            if (type == 2 || type == 3)
                dsu2.merge(start, end);

            if (type == 3) {
                if (!dsu3.isconnected(start, end))
                    dsu3.merge(start, end);
                else
                    ret++;
            }

        }

        if (dsu3.getcount() == 1)
        /* type3边已经连通 */
            return cnt1 + cnt2 + ret;

        if (dsu1.getcount() == 1 && dsu2.getcount() == 1) {
            /* type1, type2联通 */
            return cnt1 - (dsu3.getcount() - 1) + cnt2 - (dsu3.getcount() - 1) + ret;
        }

        return -1;
    }
};




