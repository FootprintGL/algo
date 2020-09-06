

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        /*
         * 动态规划
         * dp[i] - 表示从i向前，包含i，拥有的和为target的非空子数组最大数目
         * unordered_map<int, int> map - 前缀和和位置i的映射
         * 如果sums[i] - target之前没出现过，则dp[i] = dp[i - 1]
         * 如果sums[i] - target之前出现过，则dp[i] = max(dp[i - 1], dp[i - map[sum[i] - target]] + 1)
         * 为了方便边界处理，在dp前面多加一个(注意下标偏移)，在map里面家一个{0，0} - 表示sum[0]的位置坐标为0
         * 结果为dp[n]
         */
        unordered_map<int, int> map;
        int n = nums.size(), i, sum = 0;
        int cur, last;
        vector<int> dp(n + 1, 0);

        map[0] = 0;
        for (i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            sum += nums[i - 1];
            if (map.count(sum - target)) {
                last = map[sum - target];
                dp[i] = max(dp[i], dp[last] + 1);
            }
            map[sum] = i;
        }
/*
        for (i = 0; i <= n; i++)
            cout << dp[i] << " ";
        cout << endl;
*/
        return dp[n];
    }
};
