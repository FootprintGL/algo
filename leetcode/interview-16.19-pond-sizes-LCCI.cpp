

class Solution {
public:
    int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int M, N;

    /* 深度优先搜索 */
    int dfs(vector<vector<int>> &land, int x, int y) {
        int nx, ny;
        int size = 1;

        /* -1标记访问过的区域 */
        land[x][y] = -1;

        /* 8个方向上进行搜索连续水域 */
        for (int i = 0; i < 8; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                if (land[nx][ny] == 0) {
                    size += dfs(land, nx, ny);
                }
            }
        }

        return size;
    }

    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int> res;
        M = land.size();
        N = land[0].size();
        int i, j;

        for (i = 0; i < M; i++) {
            for (j = 0; j < N; j++) {
                if (land[i][j] == 0) {
                    res.push_back(dfs(land, i, j));
                }
            }
        }

        /* 池塘大小排序 */
        sort(res.begin(), res.end());

        return res;
    }
};
