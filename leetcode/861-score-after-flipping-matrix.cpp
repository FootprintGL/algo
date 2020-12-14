


class Solution {
public:
    int m;
    int n;

    /* 翻转行 */
    void reverserow(vector<vector<int>> &A, int row) {
        for (int j = 0; j < n; j++)
            A[row][j] ^= 1;
    }

    /* 反转列 */
    void reversecol(vector<vector<int>> &A, int col) {
        for (int i = 0; i < m; i++)
            A[i][col] ^= 1;
    }

    int matrixScore(vector<vector<int>>& A) {
        /*
         * 先翻转行使首位为1
         * 检查列，如果0的个数大于1的个数则做翻转
         */
        int i, j;
        m = A.size(), n = A[0].size();

        /* 首个为0，翻转 */
        for (i = 0; i < m; i++) {
            if (A[i][0] == 0)
                reverserow(A, i);
        }

        for (j = 1; j < n; j++) {
            int cnt = 0;
            /* 统计j列0的个数 */
            for (i = 0; i < m; i++)
                if (A[i][j] == 0)
                    cnt++;
            if (cnt > m / 2)
            /* 0多，翻转 */
                reversecol(A, j);
        }

        /* 计算结果 */
        int res = 0;
        for (i = 0; i < m; i++) {
            int tmp = 0;
            for (j = 0; j < n; j++)
                tmp += A[i][j] * (1 << (n - j - 1));
            res += tmp;
        }

        return res;
    }
};
