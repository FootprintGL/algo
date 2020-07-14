class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        list<int> qu;
        int cnt = 0, cnt2 = 0, res = -1;
        int m, n;
        int row, col, size;
        int i, j;

        m = grid.size();
        if (m == 0)
            return 0;

        n = grid[0].size();
        if (n == 0)
            return 0;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    cnt++;
                } else if ( grid[i][j] == 2) {
                    cnt++;
                    cnt2++;
                    qu.push_back(i);
                    qu.push_back(j);
                }
            }
        }

        if (cnt2 == cnt)
            return 0;

        /* 
         * BFS
         * cnt - 一共多少个橘子
         * cnt2 - 烂了多少个橘子
         */
        while (!qu.empty()) {
            size = qu.size();
            for (i = 0; i < size; i = i + 2) {
                row = qu.front();
                qu.pop_front();
                col = qu.front();
                qu.pop_front();
                /* 上下左右的新鲜橘子会腐烂掉 */
                if (row - 1 >= 0 && grid[row - 1][col] == 1) {
                    /* 上面橘子 */
                    qu.push_back(row - 1);
                    qu.push_back(col);
                    cnt2++;
                    grid[row - 1][col] = 2; 
                }
                if (row + 1 < m && grid[row + 1][col] == 1) {
                    /* 下面橘子 */
                    qu.push_back(row + 1);
                    qu.push_back(col);
                    cnt2++;
                    grid[row + 1][col] = 2;
                }
                if (col - 1 >= 0 && grid[row][col - 1] == 1) {
                    /* 左面橘子 */
                    qu.push_back(row);
                    qu.push_back(col - 1);
                    cnt2++;
                    grid[row][col - 1] = 2;
                }
                if (col + 1 < n && grid[row][col + 1] == 1) {
                    /* 右面橘子 */
                    qu.push_back(row);
                    qu.push_back(col + 1);
                    cnt2++;
                    grid[row][col + 1] = 2;
                }
            }
            res++;
        }

        return cnt == cnt2 ? res : -1;
    }
};
