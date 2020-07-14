
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<int> dp(row, 0);
        int t1, t2, minimum = INT_MAX;
        int i, j;

        if (row == 0)
            return 0;

        /*
         * 动态规划
         * dp[i][j] -> (i, j)位置的最小路径和
         * dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j]
         * dp[i][j]之和上面一行两个元素有关，滚动数组优化使用空间
         */
        dp[0] = triangle[0][0];
        for (i = 1; i < row; i++) {
            for (j = 0; j <= i; j++) {
                if (j == 0) {
                    /* 保存第0行dp[0]，对应第一行的dp[j - 1], 供计算第一行dp[j]使用 */
                    t1 = dp[j];
                    dp[j] = dp[j] + triangle[i][j];
                    t2 = t1;
                } else if (j == i) {
                    dp[j] = t2 + triangle[i][j];
                } else {
                    /* 保存第i行dp[j]，对应i + 1行的dp[j - 1], 供计算i + 1行dp[j]使用 */
                    t1 = dp[j];
                    dp[j] = min(dp[j], t2) + triangle[i][j];
                    t2 = t1;
                }
            }
        }

        for (i = 0; i < row; i++)
            minimum = min(minimum, dp[i]);

        return minimum;
    }
};




class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<vector<int>> dp(row, vector<int>(row, 0));

        if (row == 0)
            return 0;

        /*
         * 动态规划
         * dp[i][j] -> (i, j)位置的最小路径和
         * dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j]
         */
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < row; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                } else if (j == i) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
                }
            }
        }

        int minimum = INT_MAX;
        for (int i = 0; i < row; i++)
            minimum = min(minimum, dp[row - 1][i]);

        return minimum;
    }
};
