



class Solution {
public:
    int nthUglyNumber(int n) {
        /*
         * 双指针
         * 大的丑数是小丑数的2，3，5倍，所以有3个数组
         * 每次从3个数组中取出一个最小的归并到目标数组中
         */
        vector<int> dp(n, 0);
        int p2 = 0, p3 = 0, p5 = 0;

        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = min(dp[p2] * 2, min(dp[p3] * 3, dp[p5] * 5));
            if (dp[i] == dp[p2] * 2)
                p2++;
            if (dp[i] == dp[p3] * 3)
                p3++;
            if (dp[i] == dp[p5] * 5)
                p5++;
        }

        return dp[n - 1];
    }
};
