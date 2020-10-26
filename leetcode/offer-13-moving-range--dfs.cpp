

class Solution {
public:
    int res = 0;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(int x, int y, int m, int n, int k, vector<vector<bool>> &visited) {
        //cout << x << " " << y << " " << m << " " << n << " " << k << endl;
        /* 注意是数位之和，不是坐标之和 */
        if (x < 0 || x >= m || y < 0 || y >= n || x / 10 + x % 10 + y / 10 + y % 10 > k)
            return;

        if (visited[x][y])
            return;

        visited[x][y] = true;
        res++;

        for (int i = 0; i < 4; i++) {
            int nx, ny;
            nx = x + dx[i];
            ny = y + dy[i];
            dfs(nx, ny, m, n, k, visited);
        }
    }

    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        /* dfs回溯算法 */
        dfs(0, 0, m, n, k, visited);
        return res;
    }
};
