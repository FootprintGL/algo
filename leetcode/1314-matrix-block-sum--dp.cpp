

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sums(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> res(m, vector<int>(n, 0));
        int lr, lc, rr, rc;
        int i, j;

        /* 前缀和 */
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                sums[i][j] = mat[i - 1][j - 1] + sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
                //cout << sums[i][j] << " ";
            }
            //cout << endl;
        }

        //cout << endl;

        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                /* 计算区域左上角(lr, lc)和右下角坐标(rr, rc) */
                lr = max(1, i - K);
                lc = max(1, j - K);
                rr = min(m, i + K);
                rc = min(n, j + K);
                /* 计算区域元素和 */
                res[i - 1][j - 1] = sums[rr][rc] - sums[lr - 1][rc] - sums[rr][lc - 1] + sums[lr - 1][lc - 1];
                //cout << res[i - 1][j - 1] << " ";
            }
            //cout << endl;
        }

        return res;
    }
};
