

class Solution {
public:
    /* 子树的节点数 */
    vector<int> nodenum;
    /* 子树根节点到子树中节点的距离和 */
    vector<int> nodedis;
    /* 无向连通树 */
    vector<vector<int>> graph;

    void postorder(int root, int parent) {
        for (auto &nei : graph[root]) {
            if (nei == parent)
            /* 跳过父节点 */
                continue;
            postorder(nei, root);
            /* 所有子树节点个数之和加1 */
            nodenum[root] += nodenum[nei];
            /* root到子树各节点距离比子树根节点到各节点多走一步 */
            nodedis[root] += nodedis[nei] + nodenum[nei];
        }
    }

    void preorder(int root, int parent) {
        for (auto &nei : graph[root]) {
            if (nei == parent)
            /* 跳过父节点 */
                continue;
            /*
             * 子树根节点到子树各节点的距离比父节点少了nodenum[nei]
             * 子树根节点到子树外各节点距离比父节点多了nodenum[nei]
             */
            nodedis[nei] = nodedis[root] - nodenum[nei] + graph.size() - nodenum[nei];
            preorder(nei, root);
        }
    }

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        if (N == 1)
            return {0};

        /*
         * 递归 - 两次dfs
         * 第一次 - 从下往上
         * nodedis[root] = sum(nodedis[nei] + nodenum[root])
         * nodenum[root] = sum(nodenum[nei]) + 1
         * 第二次 - 从下往上
         * nodedis[nei] = nodedis[root] - nodenum[nei] + N - nodenum[nei]
         * 节点到所有节点的距离之二和 = 节点到子树中所有节点距离之和 + 节点到子树外所有节点距离之和
         */
        nodedis.assign(N, 0);
        nodenum.assign(N, 1);
        graph.resize(N);

        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        postorder(0, -1);
        preorder(0, -1);

        return nodedis;
    }
};
