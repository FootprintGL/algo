

class Solution {
public:
    int m;
    int n;
    int res;

    /* 边长为与边界和水域相邻的边长 */
    void dfs(vector<vector<int>> &grid, int r, int c) {
        //cout << r << " " << c << " " << m << " " << n << endl;
        if (r < 0 || r >= m || c < 0 || c >= n) {
            res++;
            return;
        }

        if (grid[r][c] == 0) {
            res++;
            return;
        }

        if (grid[r][c] == 2)
            return;

        grid[r][c] = 2;
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        res = 0;
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    break;
                }
            }
        }

        return res;
    }
};
