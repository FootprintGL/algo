

struct distance {
    int x;
    int y;
    int step;
    distance(int i, int j, int s) {
        x = i;
        y = j;
        step = s;
    }
};

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    int m, n;

    /* 第一个岛屿置2 */
    void dfs(vector<vector<int>> &A, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || A[i][j] != 1)
            return;

        //cout << i << " " << j << " " << m << " " << n << endl;
        A[i][j] = 2;

        for (int k = 0; k < 4; k++) {
            dfs(A, i + dx[k], j + dy[k]);
        }
    }

    void dump(vector<vector<int>> &A) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int shortestBridge(vector<vector<int>>& A) {
        /* 先DFS对第一个岛屿进行标记(设为2)，再BFS从第二个岛屿向外扩展 */
        int i, j;
        bool find = false;
        m = A.size(), n = A[0].size();

        //dump(A);
        /* DFS把第一个岛屿标记成2 */
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (A[i][j] == 1) {
                    dfs(A, i, j);
                    find = true;
                    break;
                }
            }
            if (find)
                break;
        }

        //dump(A);
        /* 第二个岛屿的点放入队列，距离初始化为0 */
        queue<struct distance> qu;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (A[i][j] == 1) {
                    qu.push({i, j, 0});
                }
            }
        }

        /* 搜索到第一个岛屿的最小间距 */
        while (!qu.empty()) {
            struct distance dist = qu.front();
            qu.pop();
            for (int l = 0; l < 4; l++) {
                int nx = dist.x + dx[l];
                int ny = dist.y + dy[l];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n || A[nx][ny] == 1)
                    continue;

                if (A[nx][ny] == 2) {
                    /* 找到最小距离 */
                    return dist.step;
                }

                A[nx][ny] = 1;
                qu.push({nx, ny, dist.step + 1});
            }
        }
        //dump(A);

        return -1;
    }
};
