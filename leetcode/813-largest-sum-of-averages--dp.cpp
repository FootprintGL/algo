
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        /*
         * 动态规划
         * dp[i][j] - 前i个数字分成j组能得到的最大分数
         * dp[i][j] = max{sum(A[i] + ... + A[k]) / (i - k + 1), dp[k - 1][j - 1]}, k = i -> K - 1
         * dp[i][1] 为前缀和的平均值
         * 结果为dp[n][K]
         */
        int n = A.size();
        vector<vector<double>> dp (n + 1, vector<double>(K + 1, 0));
        vector<double> sum(n + 1, 0);
        int i, j, k;

        /* 计算前缀和dp[i][1] */
        for (i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + A[i - 1];
            dp[i][1] = sum[i] / i;
        }

        for (j = 2; j <= K; j++) {
            for (i = j; i <= n; i++) {
                for (k = i - 1; k >= j - 1; k--) {
                    dp[i][j] = max(dp[i][j], dp[k][j - 1] + (sum[i] - sum[k]) / (i - k));
                }
            }
        }

/*
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= K; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
*/
        return dp[n][K];
    }
};


class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        /*
         * 动态规划
         * dp[i][j] - 前i个数字分成j组能得到的最大分数
         * dp[i][j] = max{sum(A[i] + ... + A[k]) / (i - k + 1), dp[k - 1][j - 1]}, k = i -> K - 1
         * dp[i][1] 为前缀和的平均值
         * 结果为dp[n][K]
         */
        int n = A.size();
        vector<vector<double>> dp (n, vector<double>(K + 1, 0));
        vector<double> sum(n + 1, 0);
        int i, j, k;

        /* 计算前缀和 */
        for (i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + A[i];
        }

        /* 计算dp[i][1] */
        for (i = 0; i < n; i++)
            dp[i][1] = sum[i + 1] / (i + 1);

        for (j = 2; j <= K; j++) {
            for (i = j - 1; i < n; i++) {
                for (k = i; k >= j - 1; k--) {
                    dp[i][j] = max(dp[i][j], dp[k - 1][j - 1] + (sum[i + 1] - sum[k]) / (i - k + 1));
                }
            }
        }
/*
        for (i = 0; i < n; i++) {
            for (j = 0; j <= K; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
*/
        return dp[n - 1][K];
    }
};
