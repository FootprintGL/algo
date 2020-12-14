


class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        /* floyd - 弗洛伊德算法 */
        vector<bool> res;
        vector<vector<bool>> mat(n, vector<bool>(n, false));

        for (auto &p : prerequisites)
            mat[p[0]][p[1]] = true;

        for (int k = 0; k < n; k++) { //中间桥接节点
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    mat[i][j] = mat[i][j] || (mat[i][k] && mat[k][j]);
                }
            }
        }

        for (auto &q : queries)
            res.push_back(mat[q[0]][q[1]]);

        return res;
    }
};
