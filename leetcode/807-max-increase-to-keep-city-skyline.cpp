

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        /* 每个位置可以增加min(行的最高值，列的最高值) */
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rowmax(m, 0);
        vector<int> colmax(n, 0);

        for (int i = 0; i < m; i++) {
            int rmax = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > rmax)
                    rmax = grid[i][j];
            }
            rowmax[i] = rmax;
        }

        for (int j = 0; j < n; j++) {
            int cmax = 0;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] > cmax)
                    cmax = grid[i][j];
            }
            colmax[j] = cmax;
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != rowmax[i] && grid[i][j] != colmax[j])
                    res += min(rowmax[i], colmax[j]) - grid[i][j];
            }
        }

        return res;
    }
};
