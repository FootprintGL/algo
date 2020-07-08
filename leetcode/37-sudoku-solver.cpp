using namespace std;
#include <vector>
#include <iostream>

class Solution {
public:
    /* 打印日志信息 */
    void dumplog(vector<vector<char>> &board, vector<vector<int>> &row, vector<vector<int>> &col, vector<vector<int>> &box) {
        int i, j;
        cout << "board " << endl;
        for (i = 0; i < 9; i++) {
            cout << i << ": ";
            for (j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << "row " << endl;
        for (i = 0; i < 9; i++) {
            cout << i << ": ";
            for (j = 0; j < 9; j++) {
                cout << row[i][j] << " ";
            }
            cout << endl;
        }
        cout << "col " << endl;
        for (i = 0; i < 9; i++) {
            cout << i << ": ";
            for (j = 0; j < 9; j++) {
                cout << col[i][j] << " ";
            }
            cout << endl;
        }
        cout << "box " << endl;
        for (i = 0; i < 9; i++) {
            cout << i << ": ";
            for (j = 0; j < 9; j++) {
                cout << box[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    bool dfs(vector<vector<char>> &board,
        int i,
        int j,
        vector<vector<int>> &row,
        vector<vector<int>> &col,
        vector<vector<int>> &box) {
        int k;

        if (j == 9) {
            /* 处理玩一行，i++处理下一行 */
            i++;
            j = 0;
            if (i == 9) {
                /* 填玩最后一个数字[8][8]，返回true */
                return true;
            }
        }

        if (board[i][j] == '.') {
            /* [i][j]可以放置数字，从1-9中选择一个可以放置的数字 */
            for (k = 0; k < 9; k++) {
                if (row[i][k] || col[j][k] || box[i / 3 * 3 + j / 3][k])
                    continue;
                /* 找到可以放置的数字，放置数字，更新board和标记数组 */
                board[i][j] = k + 1 + '0';
                row[i][k] = k + 1;
                col[j][k] = k + 1;
                box[i / 3 * 3 + j / 3][k] = k + 1;

                /* 放置好[i][j],递归dfs放置下一个数字[i][j + 1] */
                if (dfs(board, i, j + 1, row, col, box))
                    return true;
                /*  */
                board[i][j] = '.';
                row[i][k] = 0;
                col[j][k] = 0;
                box[i / 3 * 3 + j / 3][k] = 0;
            }
        } else {
            /* [i][j]已经数字，递归dfs放置下一个数字[i][j + 1] */
            return dfs(board, i, j + 1, row, col, box);
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int> (9, 0));
        vector<vector<int>> col(9, vector<int> (9, 0));
        vector<vector<int>> box(9, vector<int> (9, 0));
        int num;
        int i, j;

        /* 
         * 定义三个9 x 9二维数组row, col, box，分别记录每一行，列和3 x 3 小格出现过哪些元素
         * 注意3 x 3小格的index = i / 3 * 3 + j / 3
         * 遍历整个数独二维数组，更新row, col, box
         */
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    num = board[i][j] - '0';
                    row[i][num - 1] = num;
                    col[j][num - 1] = num;
                    box[i / 3 * 3 + j / 3][num - 1] = num;
                }
            }
        }
        dfs(board, 0, 0, row, col, box);
    }
};

int main() {
    Solution sol;

    vector<vector<char>>board = 
    	{
	{'.','.','.','.','2','.','.','8','5'},
	{'6','.','2','.','7','.','.','.','.'},
	{'3','.','.','.','.','.','.','1','.'},
	{'7','.','.','9','.','4','.','.','.'},
	{'.','4','.','.','.','.','.','3','.'},
	{'.','.','9','.','.','5','.','2','.'},
	{'.','.','5','.','.','.','2','6','.'},
	{'2','.','.','.','8','6','1','.','.'},
	{'.','3','.','.','.','2','.','7','.'}};

    sol.solveSudoku(board);

    return 0;
}

