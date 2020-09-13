
class Solution {
public:
    int res;

    void dfs(vector<vector<int>> &adj, int n, int cur, int k) {
        if (k == 0) {
            if (cur == n - 1) {
                res++;
            }
            return;
        }

        for (int i = 0; i < adj[cur].size(); i++) {
            dfs(adj, n, adj[cur][i], k - 1);
        }
    }

    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> adj(n);
        res = 0;

        /* 邻接表 */
        for (int i = 0; i < relation.size(); i++)
            adj[relation[i][0]].push_back(relation[i][1]);

        /* 深度优先搜索 */
        dfs(adj, n, 0, k);

        return res;
    }
};
