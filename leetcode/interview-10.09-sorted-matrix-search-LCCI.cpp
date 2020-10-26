


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
         * 从右上角开始搜索
         * 如果元素大于target，则列index--
         * 如果元素小于target, 则行index++
         * 如果相等则返回true
         */
        int m = matrix.size();

        if (m == 0)
            return false;

        int n = matrix[0].size();
        int r = 0, c = n - 1;

        while (r < m && c >= 0) {
            if (target > matrix[r][c]) {
                r++;
            } else if (target < matrix[r][c]) {
                c--;
            } else {
                return true;
            }
        }

        return false;
    }
};
