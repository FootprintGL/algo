


class Solution {
public:
    vector<double> twoSum(int n) {
        /*
         * 动态规划
         * dp[i][j] - 投i次掷出点数j的次数
         * dp[i][j] = sum{dp[i - 1][j - k]}, k = 1 -> 6
         * 结果为dp[n][j], j = n -> 6n
         * 可能的点数为n -> 6n, 共6n - n + 1 = 5n + 1
         */
        vector<double> res (n * 5 + 1);
        vector<vector<int>> dp(n + 1, vector<int> (6 * n + 1, 0));
        double total = pow(6, n);
        int i, j, k;

        for (i = 1; i <= 6; i++) {
            dp[1][i] = 1;
        }

        for (i = 2; i <= n; i++) {
            for (j = i; j <= 6 * i; j++) {
                for (k = 1; k <= 6; k++) {
                    if (j - k >= i - 1)
                        dp[i][j] += dp[i - 1][j - k];
                }
            }
        }

        for (i = n; i <= 6 * n; i++) {
            res[i - n] = dp[n][i] / total;
        }

        return res;
    }
};


/* 暴力搜索 - 超时 */
class Solution {
public:
    int cnt;

    void method(int target, int cur, int n) {
        //cout << target << " " << cur << " " << n << endl;
        if (n == 0) {
            if (cur == target)
                cnt++;
            return;
        }

        for (int i = 1; i <= 6; i++) {
            if (cur + i > target)
                break;
            cur += i;
            method(target, cur, n - 1);
            cur -= i;
        }
    }

    vector<double> twoSum(int n) {
        /* 可能的点数为n -> 6n, 共6n - n + 1 = 5n + 1 */
        vector<double> res (n * 5 + 1);

        double total = pow(6, n);
        for (int i = 0; i < 5 * n + 1; i++) {
            cnt = 0;
            method(i + n, 0, n);
            res[i] = cnt / total;
        }

        return res;
    }
};
