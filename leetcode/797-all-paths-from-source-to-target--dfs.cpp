

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<vector<int>> &graph, int cur, int n) {
        path.push_back(cur);

        if (cur == n - 1) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < graph[cur].size(); i++) {
            dfs(graph, graph[cur][i], n);
            /* 回溯 */
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 0)
            return res;
        dfs(graph, 0, n);
        return res;
    }
};
