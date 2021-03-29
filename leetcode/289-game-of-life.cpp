



class Solution {
    int m;
    int n;
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

public:
    bool isvalid(int row, int col) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }

    int cntlive(vector<vector<int>> &boardcopy, int row, int col) {
        /* 统计[row, col]四周活细胞的个数 */
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if (isvalid(nrow, ncol) && boardcopy[nrow][ncol] == 1)
                cnt++;
        }

        return cnt;
    }

    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();

        vector<vector<int>> boardcopy = board;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = cntlive(boardcopy, i, j);
                if (boardcopy[i][j] == 0 && cnt == 3)
                    board[i][j] = 1;
                else if (boardcopy[i][j] == 1 && (cnt < 2 || cnt > 3))
                    board[i][j] = 0;
            }
        }
    }
};
