

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /*
         * 位置变化规律如下
         * {row, col} -> {col, n - row - 1}
         * {col, n - row - 1} -> {n - row - 1, n - col - 1}
         * {n - row - 1, n - col - 1} -> {n - col - 1, row}
         * {n - col - 1, row} -> {row, col}
         */
        int n = matrix.size();
        for (int row = 0; row < n / 2; row++) {
            for (int col = 0; col < (n + 1) / 2; col++) {
                int t = matrix[row][col];
                matrix[row][col] = matrix[n - col - 1][row];
                matrix[n - col - 1][row] = matrix[n - row - 1][n - col -1];
                matrix[n - row - 1][n - col - 1] = matrix[col][n - row - 1];
                matrix[col][n - row - 1] = t;
            }
        }
    }
};
