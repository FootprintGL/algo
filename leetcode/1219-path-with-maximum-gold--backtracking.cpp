

class Solution {
public:
    int res;
    int m, n;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};

    /* 回溯算法 */
    void dfs(vector<vector<int>> &grid, int x, int y, int &cur, vector<vector<bool>> &visited) {
        if (x < 0 || x >= m || y < 0 || y >=n || grid[x][y] == 0 || visited[x][y]) {
            if (res < cur)
                res = cur;
            return;
        }

        visited[x][y] = true;
        cur += grid[x][y];

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            dfs(grid, nx, ny, cur, visited);
        }

        /* 回溯 */
        cur -= grid[x][y];
        visited[x][y] = false;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        res = 0;
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        int cur = 0;
        int i, j;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j])
                    dfs(grid, i, j, cur, visited);
            }
        }

        return res;
    }
};
