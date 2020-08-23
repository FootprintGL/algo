


class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int> (n + 2, -1));
        int tmp;
        int i, j, k;

        /*
         * 动态规划
         * dp[i][j] - i到j范围猜到正确数字至少需要拥有多少现金, i <= j
         * dp[i][j] = min{max{dp[i][k - 1], dp[k + 1][j]} + k} k = i -> j
         * 边界条件: dp[i][i] = 0 - 只剩最后一个必能猜中，不需要罚金
         * 长度从2到n，需要斜着遍历
         * 结果为dp[1][n]
         */
        for (i = 1; i <= n; i++)
            dp[i][i] = 0;

        for (j = 2; j <= n; j++) {
            for (i = 1; i <= n - j + 1; i++) {

                for (k = i; k <= i + j - 1; k++) {
                    tmp = -1;
                    if (i <= k - 1)
                        tmp = dp[i][k - 1] + k;
                    if (k + 1 <= i + j - 1)
                        tmp = max(tmp, dp[k + 1][i + j - 1] + k);
                    if (dp[i][i + j - 1] == -1 || dp[i][i + j - 1] > tmp)
                        dp[i][i + j - 1] = tmp;
                }
            }
        }
/*
        cout << "dp: " << endl;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
*/
        return dp[1][n];
    }
};


/*
 * 下面算法错误
 * n = 4: {1,2,3,4} 按下面二分算法先猜2, 在猜3,即可猜到结果，但这并不是最有解
 * 可以先猜1，再猜3,也可以得到最后结果
 */
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        int i, j, mid;

        /*
         * 动态规划 - 二分法
         * dp[i][j] - i到j范围猜到正确数字至少需要拥有多少现金
         * 每次猜中间的值mid = i + (j - i) / 2，而且每次都猜错
         * 直到最后一个才猜中需要花费的现金
         * dp[i][j] = max{dp[i][mid - 1], dp[mid + 1][j]} + mid
         * 边界条件: dp[i][i] = 0 - 只剩最后一个必能猜中，不需要罚金
         * 结果为dp[1][n]
         */
        for (j = 2; j <= n; j++) {
            for (i = 1; i <= n - j + 1; i++) {
                mid = i + (j - 1) / 2;
                dp[i][i + j - 1] = max(dp[i][mid - 1], dp[mid + 1][i + j - 1]) + mid;
            }
        }

        return dp[1][n];
    }
};
