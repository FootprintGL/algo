
/* 0-1背包问题变种 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        /*
         * 动态规划
         * 该题实际求从数组中拿出一个子集，使得子集和刚好是所有元素和的一半
         * dp[i][j] - 能否从前i个元素中选出若干个使得和为j
         * dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]] || nums[i] == j
         * 初始条件: dp[0][0] = false -> 正整数不能组合成0
         * 结果为dp[len - 1][target]
         */
        int len = nums.size();
        if (len == 0)
            return false;
        int sum = 0;
        for (int i = 0; i < len; i++)
            sum += nums[i];

        /* 奇数不可能 */
        if (sum % 2)
            return false;
        int target = sum / 2;

        vector<vector<bool>> dp(len, vector<bool>(target + 1, false));
        if (nums[0] <= target)
            dp[0][nums[0]] = true;

        for (int i = 1; i < len; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = dp[i - 1][j];

                if (nums[i] == j) {
                    dp[i][j] = true;
                    continue;
                }

                if (j > nums[i]) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                }
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
            /* 只要最后一列有一个为true，则从该行到结束都为true，因为dp[i][j] = dp[i - 1][j] */
            if (dp[i][target])
                return true;
        }

        return dp[len - 1][target];
    }
};
