

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int m = M.size(), n = M[0].size();
        vector<vector<int>> res(m, vector<int> (n, 0));
        int i, j, k, x, y, cnt, sum;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                cnt = 1;
                sum = M[i][j];
                for (k = 0; k < 8; k++) {
                    x = i + dx[k];
                    y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        cnt++;
                        sum += M[x][y];
                    }
                }
                res[i][j] = sum / cnt;
            }
        }

        return res;
    }
};
