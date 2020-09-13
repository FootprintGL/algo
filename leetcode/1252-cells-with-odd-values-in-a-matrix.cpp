
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        /* row,col记录对应行，列在indices出现的次数，[ri,ci]的值为row[ri] + col[ci]的值 */
        vector<int> row(n, 0);
        vector<int> col(m, 0);
        int ans = 0, i, j;

        for (i = 0; i < indices.size(); i++) {
            int ri = indices[i][0];
            int ci = indices[i][1];
            row[ri]++;
            col[ci]++;
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if ((row[i] + col[j]) % 2)
                    ans++;
                //cout << row[i] + col[j] << " ";
            }
            //cout << endl;
        }

        return ans;
    }
};
