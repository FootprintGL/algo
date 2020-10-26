class Solution {
public:
    /* 对行列对角线求和判断是否为m * 'X' 或者 m * 'O'*/
    string tictactoe(vector<string>& board) {
        int m = board.size();
        int i, j;
        bool hasempty = false;
        int row, col, leftdia = 0, rightdia = 0;

        for (i = 0; i < m; i++) {
            row = 0;
            col = 0;

            for (j = 0; j < m; j++) {
                row += board[i][j]; //行
                col += board[j][i]; //列
                if (board[i][j] == ' ')
                    hasempty = true;
            }
 
            if (row == m * 'X' || col == m * 'X')
                return string("X");

            if (row == m * 'O' || col == m * 'O')
                return string("O");

            leftdia += board[i][i]; //主对角线
            rightdia += board[i][m - i - 1]; //副对角线

            if (leftdia == m * 'X' || rightdia == m * 'X')
                return string("X");

            if (leftdia == m * 'O' || rightdia == m * 'O')
                return string("O");
        }
       
        return hasempty ? "Pending" : "Draw";
    }
};



class Solution {
public:
    /* 依次检查行列和对角线 */
    string tictactoe(vector<string>& board) {
        string res;
        int m = board.size();
        int i, j;
        bool hasempty = false;
        char c;

        /* 检测行 */
        for (i = 0; i < m; i++) {
            if (board[i][0] != ' ') {
                c = board[i][0];
                for (j = 1; j < m; j++)
                    if (board[i][j] != c)
                        break;

                if (j == m) {
                    res = c;
                    return res;
                }
            }
        }

        /* 检测列 */
        for (j = 0; j < m; j++) {
            if (board[0][j] != ' ') {
                c = board[0][j];

                for (i = 1; i < m; i++)
                    if (board[i][j] != c)
                        break;

                if (i == m) {
                    res = c;
                    return res;
                }
            }
        }

        /* 对角线 */
        if (board[0][0] != ' ') {
            c = board[0][0];
            for (i = 1; i < m; i++)
                if (board[i][i] != c)
                    break;

            if (i == m) {
                res = c;
                return res;
            }
        }

        if (board[0][m - 1] != ' ') {
            c = board[0][m - 1];
            for (i = 1; i < m; i++)
                if (board[i][m - i - 1] != c)
                    break;

            if (i == m) {
                res = c;
                return res;
            }
        }

        /* 查看有没有空格 */
        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                if (board[i][j] == ' ')
                    hasempty = true;
            }
        }

        return hasempty ? "Pending" : "Draw";
    }
};
