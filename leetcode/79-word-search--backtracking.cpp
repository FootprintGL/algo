

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int m;
    int n;

    void dumpvisited(vector<vector<bool>> &visited) {
        cout << "visited: " << endl;
        for (int i = 0; i < visited.size(); i++) {
            for (int j = 0; j < visited[0].size(); j++)
                cout << visited[i][j] << " ";
            cout << endl;
        }
    }

    bool dfs(vector<vector<char>> &board, int x, int y, int start, string &word, vector<vector<bool>> &visited) {
        //cout << x << " " << y << " " << start << " " << word[start] << endl;
        //dumpvisited(visited);
        //cout << endl;

        if (board[x][y] != word[start])
            return false;

        if (start == word.size() - 1)
            return true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && visited[nx][ny] == false) {
                visited[nx][ny] = true;
                if (dfs(board, nx, ny, start + 1, word, visited))
                    return true;
                visited[nx][ny] = false;
            }
        }

        return false;
    }

    void resetvisited(vector<vector<bool>> &visited) {
        for (int i = 0; i < visited.size(); i++)
            for (int j = 0; j < visited[0].size(); j++)
                visited[i][j] = false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));

        /* 回溯算法 */
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    resetvisited(visited);
                    visited[i][j] = true;
                    if (dfs(board, i, j, 0, word, visited))
                        return true;
                }
            }
        }

        return false;
    }
};
