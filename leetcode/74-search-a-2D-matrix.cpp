


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
         * 二分查找 - 二位矩阵可以看成m * n的一维有序数组
         * 矩阵从左到右递增，从上到下递增，并且下面行的数据大于前面行的数据
         * 行号 r = index / n, 列号 c = index % n
         */
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        if (n == 0)
            return false;

        int left = 0, right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int r = mid / n;
            int c = mid % n;

            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
         * 矩阵从左到右递增，从上到下递增，并且下面行的数据大于前面行的数据
         * 从右上角往左下角搜索: 如果target大，往下移动，如果target往左移动
         * 一旦往左移动，如果找不到则返回false，因为下一行大于上一行
         */
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        if (n == 0)
            return false;
        int r = 0, c = n - 1;
        bool r2l = false;

        while (r < m && c >= 0) {
            if (target > matrix[r][c]) {
                if (r2l)
                    return false;
                /* 向下搜索 */
                r++;
            } else if (target < matrix[r][c]) {
                /* 往左搜索，并且target只能在这一行 */
                r2l = true;
                c--;
            } else {
                /* 找到结果 */
                return true;
            }
        }

        return false;
    }
};
