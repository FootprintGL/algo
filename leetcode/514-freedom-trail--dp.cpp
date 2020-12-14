


class Solution {
public:
    int findRotateSteps(string ring, string key) {
        /*
         * 动态规划
         * dp[i][j] - 从前往后拼出key的第i个字符，ring的第j个字符与12：00方向对齐的最小步数
         * 只有当ring的第j个字符与key的第i个字符相同时，才能拼出key的第i个字符
         * 只需要考虑key[i]在ring中出现的下标集合，pos[c]记录字符c在ring中出现的下标集合
         * dp[i][j] = min{dp[i - 1][k] + min{abs(j - k), n - abs(j - k))} + 1}, k -> pos[key[i - 1]]
         * 结果为：min{dp[m - 1][j]}, j: 0 -> n - 1
         */
        int res;
        int n = ring.length(), m = key.length();
        vector<int> pos[26];
        int i, j, k;

        for (i = 0; i < n; i++) {
            pos[ring[i] - 'a'].push_back(i);
        }
        vector<vector<int>> dp(m, vector<int> (n, INT_MAX));

        /* 初始条件dp[0][i] */
        for (auto &i : pos[key[0] - 'a'])
            dp[0][i] = min(i, n - i) + 1;

        /* 更新dp表 */
        for (i = 1; i < m; i++) {
            for (auto &j : pos[key[i] - 'a']) {
                for (auto &k : pos[key[i - 1] - 'a']) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1);
                }
            }
        }

        /* 计算拼出key的最小步数 */
        res = INT_MAX;
        for (j = 0; j < n; j++) {
            if (res > dp[m - 1][j])
                res = dp[m - 1][j];
        }

        return res;
    }
};
