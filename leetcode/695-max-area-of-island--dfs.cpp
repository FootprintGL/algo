

class Solution {
public:
    int m;
    int n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    int area(vector<vector<int>> &grid, int row, int col) {
        int res = 1;

        grid[row][col] = 0;
        for (int i = 0; i < 4; i++) {
            int x = row + dx[i];
            int y = col + dy[i];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                res += area(grid, x, y);
            }
        }

        return res;
    }

    /* DFS */
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int tmp = area(grid, i, j);
                    //cout << i << " " << j << " " << tmp << " " << res << endl;
                    if (tmp > res)
                        res = tmp;
                }
            }
        }

        return res;
    }
};
