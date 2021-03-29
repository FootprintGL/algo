

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        /* 统计行列上的服务器数量 */
        vector<int> cntrow(m, 0);
        vector<int> cntcol(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    cntrow[i]++;
                    cntcol[j]++;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && (cntrow[i] > 1 || cntcol[j] > 1))
                /* 行或列服务器数量大于1 */
                    res++;
            }
        }

        return res;
    }
};
