

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        /* 检查每个元素是否和左上角元素相等 */
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++)
                if (i >= 1 && j >= 1 && matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
        }

        return true;
    }
};
