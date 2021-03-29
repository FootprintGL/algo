
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        /* 遍历方向由层数决定，而层数即为横坐标和纵坐标之和 */
        int m = matrix.size();
        if (m == 0)
            return {};
        int n = matrix[0].size();
        if (n == 0)
            return {};

        vector<int> res(m * n, 0);
        int r = 0, c = 0;

        for (int i = 0; i < m * n; i++) {
            //cout << r << " " << c << " " << m << " " << n << " " << i << endl;
            res[i] = matrix[r][c];
            if ((r + c) % 2) {
                /* 奇数向下遍历 */
                if (r == m - 1) {
                    /* 向下移动一格，准备向上遍历 */
                    c++;
                } else if (c == 0) {
                    /* 向右移动一格，准备向右移动 */
                    r++;
                } else {
                    /* 向下移动 */
                    r++;
                    c--;
                }
            } else {
                /* 偶数向上遍历 */
                if (c == n - 1) {
                    /* 往右移动一格，准备向下遍历 */
                    r++;
                } else if (r == 0) {
                    /* 向下移动一格，准备向下遍历 */
                    c++;
                } else {
                    /* 向上移动 */
                    r--;
                    c++;
                }
            }
        }
        
        return res;
    }
};



/* 访问越界 - 中间对角线移动到右上角时只能想下移动，移动到左下角时只能向有移动 */
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        if (m == 0)
            return res;
        int n = matrix[0].size();
        if (n == 0)
            return res;

        vector<int> res;
        /* 从左上角开始遍历 */
        int r = 0, c = 0;
        /* true: 先左向右，false: 再右向左 */
        bool flag = true;

        /* 遍历到右下角元素结束 */
        while () {
            res.push_back(matrix[r][c]);

            if (r == m - 1 || c == n - 1)
                break;

            if (flag) {
                /* 从左向右 */
                r--;
                c++;
            } else {
                /* 从右向左 */
                r++;
                c--;
            }

            if (r >= 0 && r < m && c >= 0 && c < n) {
                res.push_back(matrix[r][c]);

                continue;
            }

            if (r < 0) {
                r = 0;
                c++;
            } else if (c >= n) {
                c = n - 1;
                r++;
            } else if (c < 0) {
                c = 0;
                r++;
            } else if (r >= m) {
                r = m - 1;
                c++;
            }
            flag != flag;
        }

        return res;
    }
};
