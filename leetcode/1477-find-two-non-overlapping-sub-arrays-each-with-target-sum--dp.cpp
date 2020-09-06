

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
         /*
         * 动态规划
         * dp[i] - 第i个元素(包含第i个)往前找到和为target的最短子数组长度
         * map<int, int>存放前缀和和对应的下标
         * 如果前缀和sum[i] - target在map中找到，i - map[sums[i] - target]是一个有效子数组
         * dp[i] = min{dp[i - 1], i - map[sums[i] - target]}
         * 计算同步更新结果
         */

        /* map存放前缀和到位置下标的映射 */
        unordered_map<int, int> map;
        int n = arr.size();
        vector<int> dp(n + 1, n + 1);
        /* 方便处理在map里添加{0, 0}，方便处理，有效位置从1开始 */
        map[0] = 0;
        int ans = n + 1;
        int sum = 0, i;

        for (i = 1; i <= n; i++) {
            sum += arr[i - 1];
            map[sum] = i;
            dp[i] = dp[i - 1];
            if (map.count(sum - target)) {
                int last = map[sum - target];
                int curlen = i - last;
                if (last >= 0 && dp[last] != n + 1) {
                    ans = min(ans, dp[last] + curlen);
                }
                dp[i] = min(dp[i], curlen);
            }
        }

/*
        for (i = 0; i <= n; i++)
            cout << dp[i] << " ";
        cout << endl;

        for (auto m : map)
            cout << m.first << " " << m.second << endl;
*/
        return ans == n + 1 ? -1 : ans;
    }
};
