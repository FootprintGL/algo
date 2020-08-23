
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        /*
         * 动态规划
         * dp[i][j] - 以A[i],A[j]结尾的最长等差子序列的长度....A[i]A[j]
         * A[i]得前一个元素为target = A[i] - (A[j] - A[i]) = 2 * A[i] - A[j]
         * 如果target在A[0 ~ i - 1]中，dp[i][j] = dp[target][i] + 1
         * 如果target不在A[0 ~ i - 1]中，dp[i][j] = 2
         * 定义一个map{A[i], i}从数组值反向查询位置坐标
         */
        unordered_map<int, int> mp;
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int target, ans = 2;
        int i, j;

        /* 注意：不能在这里更新mp，存在重复元素，mp会被覆盖导致 */
        /*
        for (i = 0; i < n; i++)
            mp[A[i]] = i;
        */

        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                target = 2 * A[i] - A[j];
                /* mp[target]值一定小于i，条件mp[target] < i可以忽略 */
                //if (mp.count(target) && mp[target] < i) {
                if (mp.count(target)) {
                    dp[i][j] = dp[mp[target]][i] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
            /* 这里更新mp，保证mp[A[i]]的值小于下一个循环的i */
            mp[A[i]] = i;
        }

        return ans;
    }
};
