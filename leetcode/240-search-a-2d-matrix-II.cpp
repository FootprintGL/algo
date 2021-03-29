

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
         * 二分法
         * 行和列都已经有序，可以从左下或右上开始搜索
         * 搜索起点
         *      左上角，向右向下都增大，不能选
         *      右下角，向左向上都减小，不能选
         *      左下角，往右走增大，往上走减小，可选
         *      右下角，往下走增大，往左走减小，可选
         */
        int m = matrix.size();
        int n = matrix[0].size();

        /* 从右上角开始搜索 */
        int r = 0, c = n - 1;

        while (r < m && c >= 0) {
            int cur = matrix[r][c];

            if (cur == target)
                return true;
            else if (cur > target)
                c--;
            else
                r++;
        }

        return false;
    }
};
