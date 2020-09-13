
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans = 0;
        int i, j, r = 8, c = 8;
        bool found = false;

        /* 找到R的位置 */
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    r = i;
                    c = j;
                    break;
                }
            }
            if (r != 8)
                break;
        }

        //cout << "1 " << r << " " << c << endl;

        /* 向左查找可以捕获的黑色卒‘p‘ */
        j = c - 1;
        while (j >= 0 && board[r][j] == '.')
            j--;
        if (j >= 0 && board[r][j] == 'p')
            ans++;

        /* 向右查找可以捕获的黑色卒‘p‘ */
        j = c + 1;
        while (j < 8 && board[r][j] == '.')
            j++;
        if (j < 8 && board[r][j] == 'p')
            ans++;

        /* 向上查找可以捕获的黑色卒‘p‘ */
        i = r - 1;
        while (i >= 0 && board[i][c] == '.')
            i--;
        if (i >= 0 && board[i][c] == 'p')
            ans++;

        /* 向下查找可以捕获的黑色卒‘p‘ */
        i = r + 1;
        while (i < 8 && board[i][c] == '.')
            i++;
        if (i < 8 && board[i][c] == 'p')
            ans++;

        return ans;
    }
};
