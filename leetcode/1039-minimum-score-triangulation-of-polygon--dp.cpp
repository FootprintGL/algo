

class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        /*
         * 动态规划
         * 对于0 ~ n - 1构成的凸多边形，考虑0和n - 1点，有某个点j它们构成三角形
         * 使得原多边形被分成一个三角形和至多2个凸多边形，转化为2个规模更小的问题
         * f(0, n - 1) = f(0, j) + f(j, n - 1) + A[0] * A[j] * A[n - 1], j = 0 -> n
         * 如果f(i, j)不能构成多角形，则f(i, j) = 0
         * 遍历1 -> n - 2的所有点找出是总分最小的j
         */
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        int i, j, k;

        /* 不能构成多边形dp为0 */
        for (i = 0; i < n; i++) {
            dp[i][i] = 0;
            if (i < n - 1)
                dp[i][i + 1] = 0;
        }

        for (i = n - 3; i >= 0; i--) {
            for (j = i + 2; j < n; j++) {
                for (k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[k] * A[j]);
                }
            }
        }
/*
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
*/
        return dp[0][n - 1];
    }
};
