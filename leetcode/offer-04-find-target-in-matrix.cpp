

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        /*
         * 行和列都已经排好序
         * 可以从左下或右上角开始搜索
         * 从右上开始搜索:
         *      a. 如果目标值等于矩阵值，找到元素
         *      b. 如果目标值小于矩阵值，向左移一列
         *      c. 如果目标值大于矩阵值，向下移一行
         */
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        if (n == 0)
            return false;

        int i = 0, j = n - 1;

        while (i < m && j >= 0) {
            //cout << i << " " << j << " " << matrix[i][j] << endl;
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                i++;
            else
                j--;
        }

        return false;
    }
};
