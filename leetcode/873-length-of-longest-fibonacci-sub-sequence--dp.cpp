

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        /*
         * 动态规划
         * dp[i][j] - 以...A[i]A[j]结尾的最长斐波那契式子序列的长度
         * dp[i][j] = dp[target][i] + 1, 如果target = A[j] - A[i]在[0, ..., i - 1]中
         * 哈希表mp<A[i],i>快速反向查找mp[target]对应的位置坐标i
         * 边计算边更新结果ans
         */
        int n = A.size();
        unordered_map<int, int> mp;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int target, ans = 2, i, j;

        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                target = A[j] - A[i];
                if (mp.count(target)) {
                    dp[i][j] = dp[mp[target]][i] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
            mp[A[i]] = i;
        }

        return ans >= 3 ? ans : 0;
    }
};
