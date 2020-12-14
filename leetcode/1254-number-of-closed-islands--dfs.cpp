

class Solution {
public:
    int m, n;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};

    bool dfs(vector<vector<int>> &grid, int row, int col) {
        if (row < 0 || row >= m || col < 0 || col >= n)
            /* 岛屿不会到达边界 */
            return false;

        if (grid[row][col] != 0)
            return true;

        /* 2 - 表示已访问过 */
        grid[row][col] = 2;

        /*
         * 四个方向都要遍历到，不能因为某个方向找到边界就退出
         * 因为这样的岛屿不完整，结果是错的
         */
        bool res = true;
        for (int i = 0; i < 4; i++) {
            int nx = row + dx[i];
            int ny = col + dy[i];
            if (!dfs(grid, nx, ny))
                res = false;
        }

        return res;
    }

    int closedIsland(vector<vector<int>>& grid) {
        /* DFS */
        int res = 0;
        m = grid.size();
        n = grid[0].size();
        int i, j;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    /* 陆地 - 寻找封闭岛屿 */
                    if (dfs(grid, i, j))
                        res++;
                }
            }
        }

        return res;
    }
};
