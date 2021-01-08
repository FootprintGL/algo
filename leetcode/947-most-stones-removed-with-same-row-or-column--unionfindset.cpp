

/* 并查集 */
class DSU {
    vector<int> parent;
    /* 集合个数 */
    int count;

public:
    DSU(int n) {
        count = n;
        for (int i = 0; i < n; i++)
            parent.push_back(i);
    }

    void merge(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            parent[rootx] = rooty;
            count--;
        }
    }

    int find(int x) {
        return x == parent[x] ? x : find(parent[x]);
    }

    int getcount() {
        return count;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        /*
         * 并查集
         */
        int n = stones.size();
        DSU dsu(n);

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                /* 如果石头i,j行或列相同，则关联二者 */
                    dsu.merge(i, j);
            }
        }

        /* 最大删除次数 = 石头总数 - 集合数 */
        return n - dsu.getcount();
    }
};


/* 并查集 */
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
    int removeStones(vector<vector<int>>& stones) {
        /*
         * 并查集
         * 对于{i，j}的石子来说，需要把行列合并，并查集是一维的
         * 可以用j + 10000代替j，将所有石头合并好之后，只需要数一下并查集
         * 中有几个集合就可以得到答案了
         */
        int n = stones.size();
        DSU dsu(20000);

        for (auto &pos : stones) {
            dsu.merge(pos[0], pos[1] + 10000);
        }

        unordered_set<int> seen;
        for (auto &pos : stones) {
            seen.insert(dsu.find(pos[0]));
        }

        return n - seen.size();
    }
};
