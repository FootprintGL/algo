
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> minrow (m, INT_MAX);
        vector<int> maxcol (n, 0);
        int i, j;

        /* 求每一行,列的最小值 */
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                minrow[i] = min(minrow[i], matrix[i][j]);
                maxcol[j] = max(maxcol[j], matrix[i][j]);
            }
        }

        /* 寻找幸运数 */
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (matrix[i][j] == minrow[i] && matrix[i][j] == maxcol[j])
                    res.push_back(matrix[i][j]);
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> minrow (m, INT_MAX);
        vector<int> maxcol (n, 0);
        int i, j;

        /* 求每一行的最小值 */
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++)
                minrow[i] = min(minrow[i], matrix[i][j]);
        }

        /* 求每一列的最小值 */
        for (j = 0; j < n; j++) {
            for (i = 0; i < m; i++)
                maxcol[j] = max(maxcol[j], matrix[i][j]);
        }

        /* 寻找幸运数 */
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (matrix[i][j] == minrow[i] && matrix[i][j] == maxcol[j])
                    res.push_back(matrix[i][j]);
            }
        }

        return res;
    }
};
