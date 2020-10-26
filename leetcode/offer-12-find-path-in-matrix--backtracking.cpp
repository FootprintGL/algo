

class Solution {
public:
    int m;
    int n;
    int dx[4] = {0, 1, 0 , -1};
    int dy[4] = {1, 0, -1, 0};

    bool dfs(vector<vector<char>> &board, int row, int col, string &path, string &target, vector<vector<bool>> &visited) {
        if (board[row][col] != target[path.length()])
        /* 无法匹配target */
            return false;

        path += board[row][col];
        visited[row][col] = true;
        if (path.length() == target.length())
        /* 找到路径 */
            return true;

        for (int i = 0; i < 4; i++) {
            /* 尝试上下左右移动 */
            int nx = row + dx[i];
            int ny = col + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny])
                continue;
            if (dfs(board, nx, ny, path, target, visited))
                return true;
        }
        /* 回溯算法 */
        path.pop_back();
        visited[row][col] = false;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        /* 回溯算法 */
        m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        string path;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, i, j, path, word, visited))
                    return true;
            }
        }

        return false;
    }
};
