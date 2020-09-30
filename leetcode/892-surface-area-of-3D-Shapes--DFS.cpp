
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int sum = 0;
        int vertoverlap = 0, leftoverlap = 0, frontoverlap = 0;

        /* 表面积为所有正方形的面积减去重叠部分的面积 */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
                /* 垂直重叠 */
                if (grid[i][j] > 1)
                    vertoverlap += grid[i][j] - 1;

                /* 从左到右重叠 */
                if (j > 0)
                    leftoverlap += min(grid[i][j], grid[i][j - 1]);

                /* 从前到后重叠 */
                if (i > 0)
                    frontoverlap += min(grid[i][j], grid[i - 1][j]);
            }
        }

        return sum * 6 - 2 * (vertoverlap + leftoverlap + frontoverlap);
    }
};




class Solution {
public:
    int res;

    void dfs(vector<vector<int>> &grid, int n, int r, int c, int prev, vector<vector<bool>> &visited) {
        //cout << r << " " << c << " " << prev << " " << res << endl;
        if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] == 0) {
            /* 移到边界或空位 */
            res += prev;
            return;
        }

        /* 有高位移到低位 - 贡献差的绝对值 */
        if (prev > grid[r][c])
            res += prev - grid[r][c];

        /* 已经访问过，返回 */
        if (visited[r][c])
            return;

        visited[r][c] = true;

        dfs(grid, n, r + 1, c, grid[r][c], visited);
        dfs(grid, n, r - 1, c, grid[r][c], visited);
        dfs(grid, n, r, c + 1, grid[r][c], visited);
        dfs(grid, n, r, c - 1, grid[r][c], visited);
    }

    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size(), cnt = 0;
        res = 0;
        vector<vector<bool>> visited (n, vector<bool> (n, false));

        /* DFS */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    cnt++;
                    if (!visited[i][j])
                        dfs(grid, n, i, j, grid[i][j], visited);
                }
            }
        }

        return res + 2 * cnt;
    }
};
