




class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        /* K的位置向8个方向分别搜索，并统计结果 */
        vector<vector<int>> grid(8, vector<int>(8, 0));
        int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
        vector<vector<int>> res;

        /* 标记皇后的位置 */
        for (int i = 0; i < queens.size(); i++) {
            grid[queens[i][0]][queens[i][1]] = 1;
        }

        for (int i = 0; i < 8; i++) {
            /* king开始向八个方向分别搜索 */
            int nx = king[0] + dx[i];
            int ny = king[1] + dy[i];
            while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                if (grid[nx][ny]) {
                    /* 找到，推出循环，查看下一个方向 */
                    res.push_back({nx, ny});
                    break;
                }
                nx += dx[i];
                ny += dy[i];
            }
        }

        return res;
    }
};
