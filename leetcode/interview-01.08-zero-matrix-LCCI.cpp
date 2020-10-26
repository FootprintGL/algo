

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /* 第一行第一列作为标记数组 */
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return;
        bool row = false, col = false;
        int m = matrix.size(), n = matrix[0].size();
        int i, j;


        // col, row分别记录第一列和第一行是否需要全部置为0
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                    if (i == 0)
                        row = true;
                    if (j == 0)
                        col = true;
                }
            }
        }

        // 因为第一列和第一行已经作为标记数组了，因此这里的更新不参与
        for (i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (j = 1; j < n; j++)
                    matrix[i][j] = 0;
            }
        }
        for (j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (i = 1; i < m; i++)
                    matrix[i][j] = 0;
            }
        }

        //cout << row << " " << col << endl;

        // 重新讨论处理第一列和第一行
        if (row) {
            for (j = 0; j < n; j++)
                matrix[0][j] = 0;
        }
        if (col) {
            for (i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> tbl;
        int m = matrix.size();
        if (m == 0)
            return;
        int n = matrix[0].size();
        if (n == 0)
            return;
        int i, j;

        /* 找出0元素的位置 */
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (matrix[i][j] == 0)
                    tbl.push_back({i, j});
            }
        }

        for (auto &p : tbl) {
            int row = p.first;
            int col = p.second;
            for (j = 0; j < n; j++)
                matrix[row][j] = 0;
            for (i = 0; i < m; i++)
                matrix[i][col] = 0;
        }
    }
};
