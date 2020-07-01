class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int res = 0;
        int la = A.size(), lb = B.size();
        vector<vector<int>> dp (la + 1, vector<int>(lb + 1, 0));
        int i, j;

        /*
         * 动态规划
         * dp[i][j]表示子数组A[0,i), B[0,j)最长公共数组的长度
         * dp[i][j] = dp[i - 1][j - 1] + (A[i - 1] == B[j - 1])
         * 遍历数组，边计算dp[i][j]边更新最大长度,最后返回最大长度
         */
        for (i = 1; i <= la; i++) {
            for (j = 1; j <= lb; j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + (A[i - 1] == B[j - 1]);
                    if (dp[i][j] > res) {
                        res = dp[i][j];
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return res;
    }
};
