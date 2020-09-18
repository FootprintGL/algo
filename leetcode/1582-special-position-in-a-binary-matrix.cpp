

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rowones(m, 0);
        vector<int> colones(n, 0);
        int i, j, ans = 0;

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                rowones[i] += mat[i][j];
                colones[j] += mat[i][j];
            }
        }

/*
        for (auto a : rowones)
            cout << a << " ";
        cout << endl;

        for (auto a : colones)
            cout << a << " ";
        cout << endl;
*/
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (mat[i][j] == 1 && rowones[i] == 1 && colones[j] == 1) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
