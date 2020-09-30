

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0, n = mat.size();
        int i, j;

        /* 左上右下 */
        for (i = 0; i < n; i++)
            sum += mat[i][i];

        /* 左下右上 */
        for (i = 0; i < n; i++)
            sum += mat[n - 1 - i][i];

        return n % 2 ? sum - mat[n / 2][n / 2] : sum;
    }
};
