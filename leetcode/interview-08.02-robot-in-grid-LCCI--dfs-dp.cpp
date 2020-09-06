class Solution {
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> path;
        int m = obstacleGrid.size();
        if (m == 0)
            return path;
        int n = obstacleGrid[0].size();
        if (n == 0 || obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return path;

        /* 
         * 动态规划 - 先判断是否有解，然后从右下往左上搜索一条可行路径
         * dp[i][j] - 能否到达[i, j]位置
         * 方便边界处理，前面个加一行和一列
         */
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        int i, j;

        /* 第一列 */
        bool can = true;
        for (i = 1; i <= m; i++) {
            if (obstacleGrid[i - 1][0] == 1)
                can = false;
            dp[i][1] = can;
        }

        /* 第一行 */
        can = true;
        for (j = 1; j <= n; j++) {
            if (obstacleGrid[0][j - 1] == 1)
                can = false;
            dp[1][j] = can;
        }

        for (i = 2; i <= m; i++) {
            for (j = 2; j <= n; j++) {
                if (obstacleGrid[i - 1][j - 1] == 0)
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
/*
        for (i = 0; i <= m; i++) {
            for (j = 0; j <= n; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
        cout << endl;
*/
        /* 无解 */
        if (!dp[m][n])
            return path;

        i = m;
        j = n;
        while (i >= 1 && j >= 1) {
            /* 倒着插入 */
            path.insert(path.begin(), {i - 1, j - 1});
            if (dp[i - 1][j])
                i--;
            else
                j--;
        }

        return path;
    }
};



class Solution {
public:
    vector<vector<int>> path;
    int m;
    int n;

    bool dfs(vector<vector<int>> &obstacleGrid, int r, int c, vector<vector<bool>> &visited) {
        visited[r][c] = true;
        path.push_back({r, c});
        if (r == m - 1 && c == n - 1)
            /* 走到终点 */
            return true;

        if (r + 1 < m && obstacleGrid[r + 1][c] == 0 && visited[r + 1][c] == false && dfs(obstacleGrid, r + 1, c, visited))
            /* 可以往下走 */
            return true;

        if (c + 1 < n && obstacleGrid[r][c + 1] == 0 && visited[r][c + 1] == false && dfs(obstacleGrid, r, c + 1, visited))
            /* 可以往右走 */
            return true;

        path.pop_back();
        return false;
    }

    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        if (m == 0)
            return path;
        n = obstacleGrid[0].size();
        if (n == 0 || obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return path;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        if (!dfs(obstacleGrid, 0, 0, visited))
            path.clear();

        return path;
    }
};


/* 超时 - 加入visited避免重复路径 */

class Solution {
public:
    vector<vector<int>> path;
    int m;
    int n;

    bool dfs(vector<vector<int>> &obstacleGrid, int r, int c) {
        vector<int> pos(2, 0);
        pos[0] = r;
        pos[1] = c;
        path.push_back({r, c});
        if (r == m - 1 && c == n - 1)
            /* 走到终点 */
            return true;

        if (r + 1 < m && obstacleGrid[r + 1][c] == 0 && dfs(obstacleGrid, r + 1, c))
            /* 可以往下走 */
            return true;

        if (c + 1 < n && obstacleGrid[r][c + 1] == 0 && dfs(obstacleGrid, r, c + 1))
            /* 可以往右走 */
            return true;

        path.pop_back();
        return false;
    }

    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        if (m == 0)
            return path;
        n = obstacleGrid[0].size();
        if (n == 0 || obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return path;

        if (!dfs(obstacleGrid, 0, 0))
            path.clear();

        return path;
    }
};
