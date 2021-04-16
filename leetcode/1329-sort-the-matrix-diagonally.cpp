

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        /*
         * 利用左对角线元素坐标i - j相等的特性(右对角线i + j相等)
         * 把同一斜边的元素放到一个数组里排序，再放回去
         */
        unordered_map<int, vector<int>> tbl;
        int m = mat.size(), n = mat[0].size();

        /* 提取对角线元素 */
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tbl[i - j].push_back(mat[i][j]);
            }
        }

        /* 斜线内部排序 */
        for (auto &dia : tbl)
            sort(dia.second.begin(), dia.second.end(), std::greater());

        /* 放回原矩阵 */
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = tbl[i - j].back();
                tbl[i - j].pop_back();
            }
        }

        return mat;
    }
};
