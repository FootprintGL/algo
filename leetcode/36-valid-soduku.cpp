
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int> (9, 0));
        vector<vector<int>> col(9, vector<int> (9, 0));
        vector<vector<int>> box(9, vector<int> (9, 0));
        int cnt = 0, num;
        int i, j;

        /*
         * 定义三个9 x 9二维数组row, col, box，分别记录每一行，列和3 x 3 小格出现过哪些元素
         * 注意3 x 3小格的index = i / 3 * 3 + j / 3
         * 遍历整个数独二维数组，检测元素是否在行，列和box中出现过，如果出现过，则返回false
         * 如果没出现过，则跟新row, col, box
         */
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    num = board[i][j] - '0';
                    if (row[i][num - 1] || col[j][num - 1] || box[i / 3 * 3 + j / 3][num - 1]) {
                        return false;
                    }
                    row[i][num - 1] = num;
                    col[j][num - 1] = num;
                    box[i / 3 * 3 + j / 3][num - 1] = num;
                }
            }
        }

        return true;
    }
};


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> myset;
        int row, col;
        int cnt = 0;
        int i, j, k;

        /* 检测行是否有相同元素 */
        for (i = 0; i < 9; i++) {
            cnt = 0;
            myset.clear();
            for (j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    cnt++;
                    myset.emplace(board[i][j]);
                }
            }
            if (myset.size() != cnt)
                return false;
        }

        /* 检测列是否有相同元素 */
        for (i = 0; i < 9; i++) {
            cnt = 0;
            myset.clear();
            for (j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    cnt++;
                    myset.emplace(board[j][i]);
                }
            }
            if (myset.size() != cnt)
                return false;
        }

        /* 
         * 检测3 x 3 小格是否有相同元素
         * 一共有9个小格依次编号为0~8
         * 每个3 x 3小格的起始坐标为(i / 3 * 3, i % 3 * 3)
         */
        for (i = 0; i < 9; i++) {
            cnt = 0;
            myset.clear();
            row = i / 3 * 3;
            col = i % 3 * 3;
            for (j = 0; j < 3; j++) {
                for (k = 0; k < 3; k++) {
                    if (board[row + j][col + k] != '.') {
                        cnt++;
                        myset.emplace(board[row + j][col + k]);
                    }
                }
            }
            if (myset.size() != cnt)
                return false;
        }

        return true;
    }
};
