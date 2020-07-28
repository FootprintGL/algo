



class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<set<int>> adj(n, set<int>());
        vector<bool> visited(n, false);
        queue<int> qu;
        int node;

        /* 构图 - 邻接表 */
        for (auto path : graph)
            adj[path[0]].insert(path[1]);

        /* BFS */
        qu.push(start);
        visited[start] = true;
        while (!qu.empty()) {
            node = qu.front();
            qu.pop();
            //cout << "node-" << node << ": ";
            for (auto n : adj[node]) {
                //cout << n << " ";
                if (visited[n])
                    continue;
                if (n == target)
                    return true;
                qu.push(n);
                visited[n] = true;
            }
            cout << endl;
        }

        return false;
    }
};
