

    class Solution {
    public:
        int maxvalue(vector<int> &arr, int i, int j) {
            int ans = 0;

            while (i <= j) {
                if (ans < arr[i])
                    ans = arr[i];
                i++;
            }

            return ans;
        }

        int maxSumAfterPartitioning(vector<int>& arr, int k) {
            /*
            * 动态规划
            * dp[i] - 前i个元素最长长度为k的最大和
            * arr[i]可以
            *      1. 自成一组             - dp[i] = dp[i - 1] + arr[i]
            *      2. 和前面组成两个一组     - dp[i] = dp[i - 2] + max(arr[i], arr[i - 1]) * 2
            *      ...
            *      k. 和前面组成k个一组      - dp[i] = dp[i - k] + max(arr[i], ..., arr[i - k + 1]) * k
            * dp[i] = max{max{arr[i] -> arr[j]} * (i - j + 1) + dp[i - j]}, j = i -> i - k + 1
            * 结果为dp[n]
            */
            int n = arr.size();
            vector<int> dp(n + 1, 0);
            int i, j;

            for (i = 1; i <= n; i++) {
                for (j = 1; j <= min(i, k); j++) {
                    dp[i] = max(dp[i], maxvalue(arr, i - j, i - 1) * j + dp[i - j]);
                }
            }

    /*
            for (i = 0; i <= n; i++) {
                cout << dp[i] << " ";
            }
            cout << endl;
    */
            return dp[n];
        }
    };
