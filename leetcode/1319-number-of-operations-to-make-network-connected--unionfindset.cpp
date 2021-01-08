

/* 并查集 */
class UnionFind {
    vector<int> parent;
    vector<int> sz;
    int num;
public:
    UnionFind(int n) {
        num = n;
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            sz.push_back(1);
        }
    }

    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        //cout << x << " " << y << " " << rx << " " << ry << endl;
        if (rx == ry)
            return;
        num--;
        cout << num << endl;
        /* 规模小的往规模大的合并 */
        if (sz[rx] < sz[ry]) {
            parent[rx] = ry;
            sz[ry] += sz[rx];
        } else {
            parent[ry] = rx;
            sz[rx] += sz[ry];
        }
        //cout << x << " - " << y << " " << parent[x] << " " << parent[y] << " " << sz[x] << " " << sz[y] << endl << endl;
    }

    int find(int x) {
        return x == parent[x] ? x : find(parent[x]);
    }

    int getnum() {
        return num;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        /*
         * 并查集 - 连接具有传递性
         * N个点需要N - 1条线就可以进行联通，如何去寻找N - 1条线
         * 考虑每一条线，如果两个点已经联通(find(p) == find(q))
         * 这条线是多余的,可以拿去当N - 1条线中的一条
         */
        int size = connections.size();
        if (size < n - 1)
            return -1;

        UnionFind unifind(n);
        for (auto &con : connections)
            unifind.merge(con[0], con[1]);

        return unifind.getnum() - 1;
    }
};
