


class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>> res(m, vector<int> (n));
        int i, j;

        /*
         * 贪心算法
         * 将第i行j列设为min{row[i], col[j]}, 同时更新row[i], col[j]
         */
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                res[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= res[i][j];
                colSum[j] -= res[i][j];
            }
        }

        return res;
    }
};
