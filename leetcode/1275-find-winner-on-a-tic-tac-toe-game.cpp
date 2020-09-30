

class Solution {
public:
    bool place(vector<vector<char>> &board, int r, int c, char a) {
        board[r][c] = a;
        int i, j, cnt;

        /* 检查第r行 */
        cnt = 0;
        for (j = 0; j < 3; j++) {
            if (board[r][j] == a)
                cnt++;
            else
                break;
        }
        if (cnt == 3)
            return true;

        /* 检查第c列 */
        cnt = 0;
        for (i = 0; i < 3; i++) {
            if (board[i][c] == a)
                cnt++;
        }
        if (cnt == 3)
            return true;

        if (r == c) {
            /* 检查左上右下对角线 */
            cnt = 0;
            for (i = 0; i < 3; i++) {
                if (board[i][i] == a)
                    cnt++;
                else
                    break;
            }
            if (cnt == 3)
                return true;

            /* {1，1} - 检查左下右上对角线 */
            if (r == 1) {
                if (board[r + 1][c - 1] == a && board[r - 1][c + 1] == a)
                    return true;
            }
        }

        /* {2，0}，{0，2} - 检查左下右上对角线 */
        cnt = 0;
        for (i = 0; i < 3; i++) {
            if (board[2 - i][i] == a)
                cnt++;
            else
                break;
        }
        if (cnt == 3)
            return true;

        return false;
    }

    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> board(3, vector<char> (3));
        int n = moves.size();

        for (int i = 0; i < n; i++) {
            char c = i % 2 ? 'O' : 'X';
            if (place(board, moves[i][0], moves[i][1], c)) {
                return c == 'X' ? "A" : "B";
            }
        }

        return n == 9 ? "Draw" : "Pending";
    }
};
