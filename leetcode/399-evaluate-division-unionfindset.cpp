

class UnionFind {
    vector<int> parent;
    vector<double> weight;
public:
    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            weight.push_back(1.0);
        }
    }

    void myunion(int x, int y, double value) {
        int rootx = find(x);
        int rooty = find(y);
        //cout << x << " " << y << " " << rootx << " " << rooty << " " << value << endl;
        if (rootx == rooty)
            return;
        parent[rootx] = rooty;
        weight[rootx] = weight[y] * value * 1.0 / weight[x];
        //cout << weight[x] << " - " << weight[y] << " " << weight[rootx] << " " << weight[rooty] << endl;
    }

    int find(int x) {
        if (x != parent[x]) {
            int origin = parent[x];
            parent[x] = find(parent[x]);
            weight[x] *= weight[origin] * 1.0;
        }
        return parent[x];
    }

    double isconnected(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        //cout << x << " -- " << y << " " << rootx << " " << rooty << endl;
        if (rootx == rooty)
            return weight[x] / weight[y];
        else
            return -1.0;
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        /*
         * 并查集
         * 变量之间的倍数具有传递性，因此可以用并查集
         * 同一集合中的两个变量可以通过某种方式计算他们的比值，即把不同变量的比值转换
         * 为相同变量的比值，从而统一比较标准
         * 如果两个变量不在同一个集合中，返回-1.0, 如果两个变量中至少有一个变量没有
         * 出现在equations出现的字符串中，也返回-1.0
         * 统一变量等同于路径压缩
         *      查询操作的路径压缩中维护权值的变化
         *      合并操作中维护权值的变化
         */
        int n = equations.size();
        UnionFind unionfind(2 * n);
        unordered_map<string, int> idmap;

        /* 构建变量与id的map */
        int id = 0;
        for (int i = 0; i < n; i++) {
            if (idmap.count(equations[i][0]) == 0) {
                idmap[equations[i][0]] = id++;
            }

            if (idmap.count(equations[i][1]) == 0) {
                idmap[equations[i][1]] = id++;
            }

            unionfind.myunion(idmap[equations[i][0]], idmap[equations[i][1]], values[i]);
        }

        /* 做查询 */
        int m = queries.size();
        vector<double> res(m, -1.0);
        for (int i = 0; i < m; i++) {
            if (idmap.count(queries[i][0]) && idmap.count(queries[i][1])) {
                res[i] = unionfind.isconnected(idmap[queries[i][0]], idmap[queries[i][1]]);
            }
        }

        return res;
    }
};
