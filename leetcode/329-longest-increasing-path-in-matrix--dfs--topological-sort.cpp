


class Solution {
public:
    vector<vector<int>> move = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int rowsize;
    int colsize;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        
        rowsize = matrix.size();
        colsize = matrix[0].size();
        queue<pair<int, int>> qu;
        vector<vector<int>> out(rowsize, vector<int> (colsize, 0));
        int ans = 0;
        int row, col;
        int size;
        pair<int, int> pos;
        int i, j, k;
        
        /*
         * 拓扑排序 - 有向无环图
         * BFS - 出度为0的定点入队
         * 出度为0的定点出队并更新相邻顶点的出度，为0则入队
         * 循环层数即为最长递增路线
         */
        
        /* 计算出度 */
        for (i = 0; i < rowsize; i++) {
            for (j = 0; j < colsize; j++) {
                for (k = 0; k < 4; k++) {
                    row = i + move[k][0];
                    col = j + move[k][1];
                    if (row >= 0 &&
                        row < rowsize &&
                        col >= 0 &&
                        col < colsize &&
                        matrix[i][j] < matrix[row][col])
                        out[i][j]++;
                }
            }
        }

        /* 出度为0的顶点入队 */
        for (i = 0; i < rowsize; i++) {
            for (j = 0; j < colsize; j++) {
                if (out[i][j] == 0)
                    qu.push({i, j});
            }
        }

        /* BFS算法 */
        while (!qu.empty()) {
            size = qu.size();
            for (i = 0; i < size; i++) {
                pos = qu.front();
                qu.pop();
                for (k = 0; k < 4; k++) {
                    row = pos.first + move[k][0];
                    col = pos.second + move[k][1];
                    /* 更新相邻顶点出度，为0则入队 */
                    if (row >= 0 &&
                        row < rowsize &&
                        col >= 0 &&
                        col < colsize &&
                        matrix[pos.first][pos.second] > matrix[row][col]) {
                        out[row][col]--;
                        if (out[row][col] == 0)
                            qu.push({row, col});
                    } 
                }
            }
            ans++;
        }

        return ans;
    }
};




class Solution {
public:
    vector<vector<int>> move = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int rowsize;
    int colsize;

    int dfs(vector<vector<int>> &matrix, int row, int col, vector<vector<int>> &memo) {
        if (memo[row][col] != 0)
            return memo[row][col];

        int newrow, newcol;
        memo[row][col]++;
        for (int i = 0; i < 4; i++) {
            newrow = row + move[i][0],
            newcol = col + move[i][1];
            if (newrow >= 0 &&
                newrow < matrix.size() &&
                newcol >= 0 &&
                newcol < matrix[0].size() &&
                matrix[row][col] < matrix[newrow][newcol])
                memo[row][col] = max(memo[row][col], dfs(matrix, newrow, newcol, memo) + 1);
        }

        return memo[row][col];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;

        rowsize = matrix.size();
        colsize = matrix[0].size();
        vector<vector<int>> memo(rowsize, vector<int> (colsize, 0));
        int ans = 0;
        int i, j;

        /* 记忆化dfs */
        for (i = 0; i < rowsize; i++) {
            for (j = 0; j < colsize; j++) {
                ans = max(ans, dfs(matrix, i, j, memo));
            }
        }

        return ans;
    }
};
