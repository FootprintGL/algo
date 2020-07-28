


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        queue<int> qu;
        int node, cnt = 0;
        int i;

        /* 构图邻接表 + 入度统计 */
        for (auto path : prerequisites) {
            adj[path[1]].push_back(path[0]);
            indegree[path[0]]++;
        }

        /*
         * BFS拓扑排序
         * 所有入度为0的顶点入队
         * 队列非空，出队并入度-1，相邻定点入度-1，如果为0，则入队
         * 处理完毕，如果所有的顶点均入队出队，则可以完成，否则不能完成
         */
        for (i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                qu.push(i);
        }

        while (!qu.empty()) {
            node = qu.front();
            qu.pop();
            cnt++;
            indegree[node]--;

            //cout << "node-" << node << ": ";
            for (auto n : adj[node]) {
                //cout << n << " " << indegree[n];
                indegree[n]--;
                if (indegree[n] == 0)
                    qu.push(n);
            }
            //cout << endl;
        }

        return cnt == numCourses;
    }
};
