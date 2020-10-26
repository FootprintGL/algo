

class Solution {
public:
    int getKthMagicNumber(int k) {
        /* 
         * 动态规划
         * 前面的结果x3/x5/x7可得到更大的数
         * res[0] * 3, res[1] * 3, ...
         * res[0] * 5, res[1] * 5, ...
         * res[0] * 7, res[1] * 7, ...
         * 将3个数列合并得到一个更长的数列
         * 定义3个指针分别指向3个数列，下一个数一定是3个指针代表的值最小的那个，更新相应的index即可
         */
        vector<int> dp(k, 0);
        int p3 = 0, p5 = 0, p7 = 0;

        dp[0] = 1;
        for (int i = 1; i < k; i++) {
            dp[i] = min(dp[p3] * 3, min(dp[p5] * 5, dp[p7] * 7));
            if (dp[i] == dp[p3] * 3)
                p3++;
            if (dp[i] == dp[p5] * 5)
                p5++;
            if (dp[i] == dp[p7] * 7)
                p7++;
        }

        return dp[k - 1];
    }
};
