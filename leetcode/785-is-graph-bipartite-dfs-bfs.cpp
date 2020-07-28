
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> qu;
        vector<int> colors(n, 0);;
        int color;
        int index;

        /*
         * BFS - 无向图遍历着色
         * 遍历图相邻节点着不同颜色，如果发现相邻节点已经着了相同颜色，则不是二分图
         * 如果能遍历完成着色，则是二分图
         */
        for (int i = 0; i < n; i++) {
            if (colors[i] == 0) {
                qu.push(i);
                colors[i] = 1;
                while (!qu.empty()) {
                    index = qu.front();
                    color = colors[index];
                    qu.pop();
                    for (auto neighbor : graph[index]) {
                        if (colors[neighbor] == 0) {
                            qu.push(neighbor);
                            colors[neighbor] = color == 1 ? 2 : 1;
                        } else if (colors[neighbor] == color) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};



class Solution {
public:
    vector<int> colors;
    bool valid;

    void dfs(int index, int color, vector<vector<int>> &graph) {
        colors[index] = color;
        int paint = color == 1 ? 2 : 1;

        for (auto neighbor : graph[index]) {
            if (colors[neighbor] == 0) {
                dfs(neighbor, paint, graph);
                if (valid == false)
                    return;
            } else if (colors[neighbor] == color) {
                valid = false;
                return;
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        colors.assign(n, 0);
        valid = true;

        /*
         * DFS - 无向图遍历着色
         * 遍历图相邻节点着不同颜色，如果发现相邻节点已经着了相同颜色，则不是二分图
         * 如果能遍历完成着色，则是二分图
         */
        for (int i = 0; i < n; i++) {
            if (colors[i] == 0)
                dfs(i, 1, graph);

            if (valid == false)
                break;
        }

        return valid;
    }
};
