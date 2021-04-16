

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        /*
         * 寻找战舰头
         * 战舰只能水平和垂直放置，所以战舰头的左边和上边一定不是X
         */
        int m = board.size();
        int n = board[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X' && (i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.'))
                count++;
            }
        }

        return count;
    }
};
