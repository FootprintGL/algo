

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        /*
         * 动态规划
         * 能进入下一层的条件是相邻两个网格中的挡板方向相同
         * 如果相邻网格同为1，则从右侧滑入下一层
         * 如果相邻网格同为-1，则从左侧滑入下一层
         * f(x)表示小球到达x层时每个小球的下标
         * f(0) = {0,1,2,...,n - 1}
         * f(x) = f(f(x - 1))
         */
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n, 0);

        /* 初始化f(0) = {0,1,2,...,n - 1} */
        for (int j = 0; j < n; j++)
            ans[j] = j;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (ans[j] == -1)
                /* 小球已被卡住 */
                    continue;

                if (grid[i][ans[j]] == 1 && ans[j] + 1 < n && grid[i][ans[j] + 1] == 1) {
                    /* 右移 */
                    ans[j]++;
                } else if (grid[i][ans[j]] == -1 && ans[j] - 1 >= 0 && grid[i][ans[j] - 1] == -1) {
                    /* 左移 */
                    ans[j]--;
                } else {
                    /* 卡住 */
                    ans[j] = -1;
                }
            }
        }

        return ans;
    }
};
