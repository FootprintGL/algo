

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        /*
         * 动态规划
         * k = 1是就是求最大子数组的和
         * dp[i] - 以arr[i]为结尾的最大子数组的和
         * dp[i] = max{dp[i - 1] + arr[i], arr[i], 0}, 子数组长度可以是0，dp[i] >= 0
         * 边计算边更新 maxvalue
         * k >= 2时
         * 1. maxvalue 就是串联后的最大子数组的和
         * 2. 最大子数组的和必是第一个数组后面取一部分，最后一个数组前面取一部分，和中间k - 2个数组
         * 数组的最大后缀 + max{0, (k - 2) * sum} + 数组的最大前缀
         */

        /* long避免整数溢出 */
        long n = arr.size();
        vector<long> sums(n + 1, 0);
        vector<long> dp(n + 1, 0);
        long maxsum = 0, minsum = 0, maxvalue = 0;
        long M = 1000000007;
        long i;

        for (i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + arr[i - 1];
            maxsum = max(maxsum, sums[i]);
            minsum = min(minsum, sums[i]);
            dp[i] = max(max(dp[i - 1] + arr[i - 1], (long)arr[i - 1]), (long)0);
            maxvalue = max(maxvalue, dp[i]);
        }

/*
        for (i = 0; i <= n; i++)
            cout << sums[i] << " ";
        cout << endl;

        for (i = 0; i <= n; i++)
            cout << dp[i] << " ";
        cout << endl;

        cout << minsum << " " << maxsum << " " << dp[n] << endl;
*/
        if (k >= 2) {
            maxvalue = max(sums[n] - minsum + maxsum + ((k - 2) * max(sums[n], (long)0)) % M, maxvalue);
        }

        return maxvalue;
    }
};
