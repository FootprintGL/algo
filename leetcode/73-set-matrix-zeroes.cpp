class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /* 该题难点在于常数空间 - 用每行，列的第一个元素做标记 */
        int m = matrix.size();
        if (m == 0)
            return;
        int n = matrix[0].size();
        if (n == 0)
            return;
        
        int i, j;
        /* 检查第一行是否有0 */
        bool row0 = false;
        for (j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                row0 = true;
                break;
            }
        }

        /* 检查第一列是否有0 */
        bool col0 = false;
        for (i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                col0 = true;
                break;
            }
        }

        //cout << row0 << " " << col0 << endl;

        /* 标记需要清零的行和列 */        
        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        /* 清零 */
        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        /* row0/col0 */
        if (row0)
            for (j = 0; j < n; j++)
                matrix[0][j] = 0;

        if (col0)
            for (i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};
