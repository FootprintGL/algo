class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int cnt = 0, n = matrix.size();
        int l, m, r;
        int i, j;

        if (n == 0)
            return 0;
        /* 
         * 二分法
         * 每行每列都按升序排序，取中值m把矩阵分成左右两边
         * 左半边元素都小于等于m，右半边大于m
         * 如果左半边个数小于k个，说明第k小的元素在右半边，介于(m, r]之间
         * 如果左边个数大于等于k个，说明第k小的元素在[l, m]之间
         * 持续缩小[l, r]区间，直到l等于r极为第k小的值
         */
        l = matrix[0][0];
        r = matrix[n - 1][n - 1];
        while (l < r) {
            i = n - 1;
            j = 0;
            cnt = 0;
            m = (l + r) / 2;
            /* 统计左边区域小于等于m的元素个数 */
            while (j < n) {
                while (i >= 0 && matrix[i][j] > m)
                    i--;
                cnt = cnt + i + 1;
                j++;
            }
            /* 如果左半边个数小于k个，说明第k小的元素在右半边，介于(m, r]之间 */
            if (cnt < k) {
                l = m + 1;
            } else {
                /* 如果左边个数大于等于k个，说明第k小的元素在[l, m]之间 */
                r = m;
            }
        }

        return r;
    }
};
