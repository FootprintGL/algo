

class Solution {
public:
    int len;
    int dir_x[8] = {-1, -1, -1, 0, 1, 1 ,1 ,0};
    int dir_y[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

    /*
     * DFS
     * 1. 如果为M, 修改为X返回
     * 2. 如果为E，统计周围有几个M
     *       a. 如果没有M，则修改为B，递归处理周围的未挖出方块
     *       b. 如果有M，修改为M的数量
     * 3. 如果为B，则直接返回面板
     */
    void helper(vector<vector<char>> &board, int x, int y) {
        if (board[x][y] == 'B')
            return;

        int nx, ny;
        int i, sum = 0;

        /* 统计周围M的数量 */
        for (i = 0; i < 8; i++) {
            nx = x + dir_x[i];
            ny = y + dir_y[i];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size())
                if (board[nx][ny] == 'M')
                    sum++;
        }

        if (sum == 0) {
            /* 周围没有地雷M */
            board[x][y] = 'B';
            for (i = 0; i < 8; i++) {
                nx = x + dir_x[i];
                ny = y + dir_y[i];
                if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size())
                    helper(board, nx, ny);
            }
        } else {
            /* 周围有地雷M */
            board[x][y] = sum + '0';
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M')
            board[click[0]][click[1]] = 'X';
        else
            helper(board, click[0], click[1]);

        return board;
    }
};
