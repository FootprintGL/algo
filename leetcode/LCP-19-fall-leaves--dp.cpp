

class Solution {
public:
    int minimumOperations(string leaves) {
        /*
         * 动态规划
         * j -> 0 : 第一部分红色，1 : 第二部分的黄色，2 : 第三部分的红色
         * dp[i][j] - 第0-i片叶子进行调整操作第i片叶子处于j是的最小操作数
         * dp[i][0] = dp[i - 1][0] + isyellow(i)
         * dp[i][1] = min{dp[i - 1][0], dp[i - 1][1]} + isred(i)
         * dp[i][2] = min{dp[i - 1][1], dp[i - 1][2]} + isyellow(i)
         * 结果为dp[n - 1][2]
         * dp[0][0] = isyellow(0)
         * dp[0][1] = dp[0][2] = dp[1][2] = INT_MAX
         */
        int n = leaves.length();
        vector<vector<int>> dp(n, vector<int> (3, 0));
        dp[0][0] = leaves[0] == 'y';
        dp[0][1] = dp[0][2] = dp[1][2] = INT_MAX;

        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + (leaves[i] == 'y');
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (leaves[i] == 'r');
            if (i >= 2)
                dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + (leaves[i] == 'y');
        }

        return dp[n - 1][2];
    }
};
