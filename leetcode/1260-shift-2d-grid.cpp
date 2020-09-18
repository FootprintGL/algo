
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int i, j;

        for (;k > 0; k--) {
            int tmp = grid[m - 1][n - 1];
            for (i = m - 1; i >= 0; i--) {
                for (j = n - 1; j >= 0; j--) {
                    if (j > 0)
                        grid[i][j] = grid[i][j - 1];
                    else {
                        if (i > 0)
                            grid[i][j] = grid[i - 1][n - 1];
                        else
                            grid[i][j] = tmp;
                    }
                }
            }
        }

        return grid;
    }
};
