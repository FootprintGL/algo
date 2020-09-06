

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        /*
         * 动态规划 - 打家劫舍变型
         * cnt[i] - 记录数字i在数组中出现的次数
         * dp[i] = max{dp[i - 1], dp[i - 2] + cnt[i] * i}
         */
        int n = nums.size();

        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        unordered_map<int, int> map;
        int maxvalue = 0, i;

        /* 哈希表统计每个元素的个数，计算最大值 */
        for (auto num : nums) {
            if (maxvalue < num)
                maxvalue = num;
            map[num]++;
        }
        /* 计算从0 ~ maxvalue各自在nums数组中出现的次数 */
        vector<int> cnt (maxvalue + 1, 0);
        for (i = 0; i <= maxvalue; i++) {
            if (map.count(i))
                cnt[i] = map[i];
        }

        vector<int> dp(maxvalue + 1, 0);
        dp[1] = cnt[1];
        dp[2] = max(cnt[1], cnt[2] * 2);
        for (int i = 3; i <= maxvalue; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
        }

        return dp[maxvalue];
    }
};
