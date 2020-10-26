


class Solution {
public:
    /* 计算(i op j)的布尔值 */
    bool calculate(int i, int j, char op) {
        if (op == '&')
            return i & j;

        if (op == '|')
            return i | j;

        return i ^ j;
    }

    /* 记忆化递归- start到end结果为result的方案数 */
    int dfs(string &s, int start, int end, int result, vector<vector<vector<int>>> &dp) {
        if (start == end) {
            return s[start] - '0' == result ? 1 : 0;
        }

        if (dp[start][end][result] != -1)
            return dp[start][end][result];

        int res = 0;
        /* k将区间[start, end]分为左右2部分，[start, k]和[k + 2, end] */
        for (int k = start; k < end; k += 2) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    /* k + 1为符号 */
                    char op = s[k + 1];
                    if (calculate(i, j, op) == result) {
                        res += dfs(s, start, k, i, dp) * dfs(s, k + 2, end, j, dp);
                    }
                }
            }
        }

        dp[start][end][result] = res;

        return res;
    }

    int countEval(string s, int result) {
        /* 记忆化搜索 */
        int n = s.size();
        /* dp[i][j][r] - i到j结果为r的方案数 */
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (2, -1)));

        return dfs(s, 0, n - 1, result, dp);
    }
};
