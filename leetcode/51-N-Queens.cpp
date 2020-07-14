class Solution {
public:
    /* 每放一个Q，对应行，列和对角线标记加1 */
    void place(vector<string> &method, int n, int row, int col, vector<vector<int>> &used) {
        int i, j;
        method[row][col] = 'Q';

        /* 行 */
        for (i = 0; i < n; i++)
            used[row][i]++;

        /* 列 */
        for (i = 0; i < n; i++)
            used[i][col]++;

        /* 行和列重复统计了[row][col] */
        used[row][col]--;

        /* 左上 */
        i = row - 1;
        j = col - 1;
        while (i >= 0 && j >= 0) {
            used[i--][j--]++;
        }

        /* 右上 */
        i = row - 1;
        j = col + 1;
        while (i >= 0 && j < n)
            used[i--][j++]++;

        /* 左下 */
        i = row + 1;
        j = col - 1;
        while (i < n && j >= 0)
            used[i++][j--]++;

        /* 右下 */
        i = row + 1;
        j = col + 1;
        while (i < n && j < n)
            used[i++][j++]++;
    }

    /* 移除[row][i]的Q，更新标记used[row][i] */
    void remove(vector<string> &method, int n, int row, int col, vector<vector<int>> &used) {
        int i, j;

        method[row][col] = '.';

        /* 行 */
        for (i = 0; i < n; i++)
            used[row][i]--;

        /* 列 */
        for (i = 0; i < n; i++)
            used[i][col]--;

        /* 行和列重复统计了[row][col] */
        used[row][col]++;

        /* 左上 */
        i = row - 1;
        j = col - 1;
        while (i >= 0 && j >= 0)
            used[i--][j--]--;

        /* 右上 */
        i = row - 1;
        j = col + 1;
        while (i >= 0 && j < n)
            used[i--][j++]--;

        /* 左下 */
        i = row + 1;
        j = col - 1;
        while (i < n && j >= 0)
            used[i++][j--]--;

        /* 右下 */
        i = row + 1;
        j = col + 1;
        while (i < n && j < n)
            used[i++][j++]--;
    }

    void dfs(vector<string> &method, int n, int row, vector<vector<int>> &used, vector<vector<string>> &res) {
        if (row == n) {
            res.push_back(method);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (used[row][i])
                continue;
            /* [row][i]放置Q，更新标记used[row][i] */
            place(method, n, row, i, used);
            dfs(method, n, row + 1, used, res);
            /* 移除[row][i]的Q，更新标记used[row][i] */
            remove(method, n, row, i, used);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> method (n, string(n, '.'));
        vector<vector<int>> used(n, vector<int>(n, 0));

        /*
         * 回溯算法
         * used[n][n]标记可以放Q位置,如果used[row][col]等于0，说明可以放置Q
         * 每放一个Q，对应行，列和对角线标记加1
         * 当回溯重置移除一个Q是，对应行，列和对角线标记减1
         * 
         */
        dfs(method, n, 0, used, res);

        return res;
    }
};
