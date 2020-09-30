

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<vector<int>> res (n, vector(m, 0));
        int i, j;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                res[j][i] = A[i][j];
            }
        }

        return res;
    }
};
