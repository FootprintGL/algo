
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        int i, j;

        /* 由外到内按层遍历 */
        int top = 0;
        int left = 0;
        int bottom = m - 1;
        int right = n - 1;
        
        while (top <= bottom && left <= right) {
            /* (top, left) -> (top, right) */
            for (j = left; j <= right; j++)
                res.push_back(matrix[top][j]);

            if (top + 1 > bottom)
                break;

            /* (top + 1, right) -> (bottom, right) */
            for (i = top + 1; i <= bottom; i++)
                res.push_back(matrix[i][right]);

            if (right - 1 < left)
                break;

            /* (bottom, right - 1) -> (bottom, left) */
            for (j = right - 1; j >= left; j--)
                res.push_back(matrix[bottom][j]);

            if (bottom - 1 < left + 1)
                break;

            /* (bottom - 1, left) -> (top + 1, left) */
            for (i = bottom - 1; i >= left + 1; i--)
                res.push_back(matrix[i][left]);
            top++;
            left++;
            right--;
            bottom--;
        }

        return res;
    }
};



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row, col;
        vector<int> res;
        int i, j, l;

        /* l记录圈数，从外圈向内圈依次处理，l行，n - l - 1行, m - l - 1行, l列 */
        for (l = 0; l < (m + 1) / 2; l++) {
            if (l > n - l - 1)
                break;

            /* i行 */
            row = l;
            for (j = l; j <= n - l - 1; j++)
                res.push_back(matrix[row][j]);

            if (row + 1 > m - l - 1)
                break;

            /* n - i - 1列 */
            col = n - l - 1;
            for (i = row + 1; i <= m - l - 1; i++)
                res.push_back(matrix[i][col]);

            if (col - 1 < l)
                break;

            /* m - l - 1行 */
            row = m - l - 1;
            for (j = col - 1; j >= l; j--)
                res.push_back(matrix[row][j]);

            if (row - 1 < l + 1)
                break;

            /* l列 */
            col = l;
            for (i = row - 1; i >= l + 1; i--)
                res.push_back(matrix[i][col]);
        }

        return res;
    }
};
