
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        queue<int> qu;
        vector<int> colors(4, 0);
        vector<int> used(4, 0);
        vector<int> res(N, 0);
        vector<vector<int>> graph(N, vector<int>());
        int node;
        int i, j;

        /* 初始化颜色列表 */
        for (i = 0; i < 4; i++)
            colors[i] = i + 1;

        /* 构图 - 邻接表*/
        for (auto path : paths) {
            graph[path[0] - 1].push_back(path[1] - 1);
            graph[path[1] - 1].push_back(path[0] - 1);
        }

        /* BFS - 每次着色之前需要提出已着色的相邻节点的颜色 */
        for (i = 0; i < N; i++) {
            if (res[i] != 0)
                continue;
            qu.push(i);
            res[i] = colors[0];
            while (!qu.empty()) {
                node = qu.front();
                qu.pop();
                for (auto t : graph[node]) {
                    if (res[t] == 0) {
                        used = colors;
                        qu.push(t);
                        /* 去掉相邻节点使用的颜色 */
                        for (auto s : graph[t]) {
                            if (res[s] != 0)
                                used[res[s] - 1] = 0;
                        }
                        /* 找一个未被使用的颜色着色 */
                        for (auto c : used) {
                            if (c != 0) {
                                res[t] = c;
                                used[c - 1] = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }

        return res;
    }
};



class Solution {
public:

    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        queue<int> qu;
        vector<int> colors(4, 0);
        vector<int> used(4, 0);
        vector<int> res(N, 0);
        vector<vector<int>> graph(N, vector<int>());
        int node;
        int i, j;

        /* 初始化颜色列表 */
        for (i = 0; i < 4; i++)
            colors[i] = i + 1;

        /* 构图 - 邻接表*/
        for (auto path : paths) {
            graph[path[0] - 1].push_back(path[1] - 1);
            graph[path[1] - 1].push_back(path[0] - 1);
        }

        /* BFS - 着色 */
        for (i = 0; i < N; i++) {
            if (res[i] != 0)
                continue;
            qu.push(i);
            res[i] = colors[0];
            while (!qu.empty()) {
                node = qu.front();
                qu.pop();
                for (auto t : graph[node]) {
                    if (res[t] == 0) {
                        used = colors;
                        //cout << "node-" << t << ": ";
                        qu.push(t);
                        /* 排除相邻节点使用的颜色 */
                        for (auto s : graph[t]) {
                            //cout << s << " ";
                            if (res[s] != 0)
                                used[res[s] - 1] = 0;
                        }
                        /*
                        cout << endl;
                        cout << "color: ";
                        for (auto c : res)
                            cout << c << " ";
                        cout << endl;

                        cout << "used1: ";
                        for (auto c : used) {
                            cout << c << " ";
                        }
                        cout << endl;*/
                        for (auto c : used) {
                            if (c != 0) {
                                res[t] = c;
                                used[c - 1] = 0;
                                break;
                            }
                        }
                        /*
                        cout << "used2: ";
                        for (auto c : used) {
                            cout << c << " ";
                        }
                        cout << endl;*/
                    }
                }
                /*
                cout << "color1: ";
                for (auto c : res)
                    cout << c << " ";
                cout << endl << endl;*/
            }
        }

        return res;
    }
};
