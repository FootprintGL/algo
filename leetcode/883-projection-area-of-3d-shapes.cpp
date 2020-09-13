
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        /*
         * 投影面积包含3部分
         *      1. 非0点的个数
         *      2. 所有行的最大值之和
         *      3. 所有列的最大值之和
         */
        int ans = 0, i, j;
        int maxvalue;

        /* 统计非0点个个数和行的最大值之和 */
        for (i = 0; i < grid.size(); i++) {
            maxvalue = grid[i][0];
            for (j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 0)
                    ans++;
                if (maxvalue < grid[i][j])
                    maxvalue = grid[i][j];
            }
            ans += maxvalue;
        }

        /* 统计列的最大值之和 */
        for (j = 0; j < grid[0].size(); j++) {
            maxvalue = grid[0][j];
            for (i = 0; i < grid.size(); i++) {
                if (maxvalue < grid[i][j])
                    maxvalue = grid[i][j];
            }
            ans += maxvalue;
        }

        return ans;
    }
};
