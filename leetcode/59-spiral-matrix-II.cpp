

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        /* 由外到内按层填充 */
        vector<vector<int>> matrix(n, vector<int> (n, 0));
        int top = 0, left = 0;
        int bottom = n - 1, right = n - 1;
        int i, j, cur = 1;


        while (top <= bottom && left <= right) {
            /* (top, left) -> (top, right) */
            for (j = left; j <= right; j++)
                matrix[top][j] = cur++;

            if (top + 1 > bottom)
                break;

            /* (top + 1, right) -> (bottom, right) */
            for (i = top + 1; i <= bottom; i++)
                matrix[i][right] = cur++;

            if (right - 1 < left)
                break;

            /* (bottom, right - 1) -> (bottom, left) */
            for (j = right - 1; j >= left; j--)
                matrix[bottom][j] = cur++;

            if (bottom - 1 < left + 1)
                break;

            /* (bottom - 1, left) -> (top + 1, left) */
            for (i = bottom - 1; i >= left + 1; i--)
                matrix[i][left] = cur++;
            top++;
            left++;
            right--;
            bottom--;
        }

        return matrix;
    }
};
