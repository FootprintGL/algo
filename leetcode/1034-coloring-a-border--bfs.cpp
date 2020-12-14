

class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    int m;
    int n;

    bool onborder(int r, int c) {
        return r == 0 || r == m - 1 || c == 0 || c == n - 1;
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        /* BFS - 连通分量边界即图色，连同边界为边界或遇到别的颜色 */
        queue<pair<int, int>> qu;
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        int oricolor = grid[r0][c0];

        qu.push({r0, c0});
        visited[r0][c0] = true;

        while (!qu.empty()) {
            auto cur = qu.front();
            int x = cur.first;
            int y = cur.second;
            qu.pop();
            if (onborder(x, y))
            /* 边界上的连通分量着色 */
                grid[x][y] = color;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) {
                    /* 越界或已经访问过了 */
                    continue;
                }
                if (grid[nx][ny] == oricolor) {
                    qu.push({nx, ny});
                    visited[nx][ny] = true;
                } else {
                    /* 连通分量着色 */
                    grid[x][y] = color;
                }
            }
        }

        return grid;
    }
};
