




class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    int m;
    int n;

    bool inarea(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void bfs(vector<vector<char>> &grid, int i, int j) {
        queue<pair<int, int>> qu;
        qu.push({i, j});
        grid[i][j] = '2';

        while (!qu.empty()) {
            pair<int, int> cur = qu.front();
            qu.pop();
            int x = cur.first;
            int y = cur.second;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (inarea(nx, ny) && grid[nx][ny] == '1') {
                    //cout << x << " " << y << " " << nx << " " << ny << endl;
                    qu.push({nx, ny});
                    grid[nx][ny] = '2';
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int res = 0;

        /* BFS */
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    res++;
                }
            }
        }

        return res;
    }
};
