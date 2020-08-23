

class NumMatrix {
public:
    int m;
    int n;
    vector<vector<int>> sums;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        if (m == 0)
            return;
        n = matrix[0].size();
        if (n == 0)
            return;
        sums.resize(m + 1);
        for (int i = 0; i <= m; i++)
            sums[i].resize(n + 1);
        cout << m << " " << n << " " << sums.size() << " " << sums[0].size() << endl;
        /* 前缀和 */
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sums[i][j] = matrix[i - 1][j - 1] + sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
                //cout << sums[i][j] << " ";
            }
            //cout << endl;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (m == 0 || n == 0)
            return 0;
        else
            return sums[row2 + 1][col2 + 1] - sums[row2 + 1][col1] - sums[row1][col2 + 1] + sums[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
