

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sum(m + 1, vector<int> (n + 1, 0));
        int i, j;

        /* 求前缀和 */
        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        /* 二分搜索 */
        int ans = 0;
        int left = 1, right = min(m, n);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            bool find = false;

            for (i = mid; i <= m; i++) {
                for (j = mid; j <= n; j++) {
                    if (sum[i][j] - sum[i - mid][j] - sum[i][j - mid] + sum[i - mid][j - mid] <= threshold) {
                        /* 正方形区域内和满足要求 */
                        find = true;
                        break;
                    }
                }
                if (find)
                    break;
            }

            if (find) {
                /* 试着扩大正方形 */
                ans = mid;
                left = mid + 1;
            } else {
                /* 试着缩小正方形 */
                right = mid - 1;
            }
        }

        return ans;
    }
};
