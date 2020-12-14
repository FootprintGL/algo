

class Solution {
public:
    /* 图的邻接图 */
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> group;

    /* DFS着色 */
    bool dfs(int node, int id) {
        if (group.count(node))
        /* node已经着色，且发生冲突 */
            return group[node] == id;

        group[node] = id;
        for (auto &n : graph[node]) {
            /* 检查相邻定点是否有冲突 */
            if (!dfs(n, id ^ 1))
                return false;
        }

        return true;
    }

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        /*
         * 无向图着色 - DFS
         * 题目要求分成2组，相邻的定点不能属于同一组
         * 对图进行深度优先遍历并着色，如果发生冲突，则不能成功分组
         * 如果没有冲突，则可以正常分组
         * 一开始想检测环来判断，发现是错的
         * 比如: [[1,2],[2,3],[3,4],[1,4]]可以分为{1，3}和{2， 4}
         */

        /* 构建邻接表 */
        for (auto &dis : dislikes) {
            graph[dis[0]].push_back(dis[1]);
            graph[dis[1]].push_back(dis[0]);
        }

        for (int i = 1; i <= N; i++) {
            /* 还未被着色 - 默认分到0组 */
            if (group.count(i) == 0 && !dfs(i, 0)) {
                return false;
            }
        }

        return true;
    }
};
