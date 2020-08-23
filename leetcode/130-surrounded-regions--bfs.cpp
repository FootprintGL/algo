


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> qu;
        int m, n;
        int i, j, k;
        pair<int, int> pos;
        int move[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        m = board.size();
        if (m < 3)
            return;

        n = board[0].size();
        if (n < 3)
            return;

        for (i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                qu.push({i, 0});
                board[i][0] = '#';
            }
            if (board[i][n - 1] == 'O') {
                qu.push({i, n - 1});
                board[i][n - 1] = '#';
            }
        }

        for (j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                qu.push({0, j});
                board[0][j] = '#';
            }
            if (board[m - 1][j] == 'O') {
                qu.push({m - 1, j});
                board[m - 1][j] = '#';
            }
        }

        /* BFS - 和边缘'O'联通的O提供换成'#' */
        while (!qu.empty()) {
            pos = qu.front();
            qu.pop();
            for (k = 0; k < 4; k++) {
                i = pos.first + move[k][0];
                j = pos.second + move[k][1];
                if (i > 0 && i < m - 1 && j > 0 && j < n - 1 && board[i][j] == 'O') {
                    qu.push({i, j});
                    board[i][j] = '#';
                }
            }
        }

        /* 替换’O’为‘X‘, 还原'#'为'O' */
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};
