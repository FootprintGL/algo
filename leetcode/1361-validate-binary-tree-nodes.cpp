class Solution {
    // 定义并查集
    int count;
    vector<int> parent;
    vector<int> size;
    void initUF(int n) {
        count = n;
        parent.assign(n, 0);
        size.assign(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int find(int a) {
        while (parent[a] != a) {
            parent[a] = parent[parent[a]];
            a = parent[a];
        }
        return a;
    }
    void uni(int a, int b) {
        int roota = find(a);
        int rootb = find(b);
        if (roota == rootb) return;
        if (size[roota] <= size[rootb]) {
            parent[roota] = rootb;
            size[rootb] += size[roota];
        } else {
            parent[rootb] = roota;
            size[roota] += size[rootb];
        }
        --count;
    }
    bool connected(int a, int b) {
        int roota = find(a);
        int rootb = find(b);
        return roota == rootb;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        /*
         * 并查集
         * 对left, right每个关系进行合并
         * 如果left, right在同一个集合，则存在环
         * 最终只有一个集合，则是二叉树，否则不是二叉树
         */
        // 使用并查集求解，每一次合并操作不能产生环（与在同一个集合中的元素合并），最终集合数量为1
        initUF(n);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                if (connected(i, leftChild[i])) return false; // 如果i和i的孩子节点已经在同一个集合中，那么存在环
                uni(i, leftChild[i]);
            }
            if (rightChild[i] != -1) {
                if (connected(i, rightChild[i])) return false;  // 如果i和i的孩子节点已经在同一个集合中，那么存在环
                uni(i, rightChild[i]);
            }
        }
        // 连通分量等于1，则是二叉树
        return count == 1;
    }
};



class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        /*
         * 二叉树
         * 只有一个根节点入度为0，其他节点入为1
         * 每个节点出度小于等于2 - 题目可以保证
         */
        vector<int> din(n, 0);

        /* 统计每个节点入度 */
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                din[leftChild[i]]++;
                if (din[leftChild[i]] > 1)
                    return false;
            }
            if (rightChild[i] != -1) {
                din[rightChild[i]]++;
                if (din[rightChild[i]] > 1)
                    return false;
            }
        }

        int zeroincnt = 0, index = 0;
        for (int i = 0; i < n; i++) {
            if (din[i] == 0) {
                zeroincnt++;
                index = i;
            }
        }

        /* 只有一个入度为0的根节点 */
        if(zeroincnt != 1)
            return false;

        /* 从根节点开始BFS遍历，若能遍历到所有节点则为二叉树 */
        queue<int> qu;
        unordered_set<int> visited;
        visited.insert(index);
        qu.push(index);
        while (!qu.empty()) {
            int cur = qu.front();
            qu.pop();
            if (leftChild[cur] != -1) {
                visited.insert(leftChild[cur]);
                qu.push(leftChild[cur]);
            }
            if (rightChild[cur] != -1) {
                visited.insert(rightChild[cur]);
                qu.push(rightChild[cur]);
            }
        }

        return visited.size() == n;
    }
};
