

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        /*
         * 动态规划
         * 假设已经找打一个子集，拿到一个新的数
         *      1. 如果新的数能整除最大的数, 可以加入子集
         *      2. 如果新的数能被最小的数整除，也可以加入字迹
         * 先对结果排序
         * dp[i] - 以nums[i]为结尾的最长有效子集长度
         * dp[i] = max(dp[j] + 1), nums[i]能整除dp[j]
         * pre[i] 计算前一个元素的下表
         * 边计算边更新最长子集长度
         */
        int n = nums.size();
        if (n == 0)
            return {};
        /* dp数组 */
        vector<int> dp(n, 1);
        /* 记录nums[i]结尾最长子集的前一个元素下标 */
        vector<int> pre(n, -1);
        vector<int> res;
        /* 当前最长子集的末尾下标 */
        int end = 0;
        /* 当前最长子集长度 */
        int ans = 1;
        int i, j;

        sort(nums.begin(), nums.end());

        for (i = 1; i < n; i++) {
            for (j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                    }
                }
            }
            if (ans < dp[i]) {
                end = i;
                ans = dp[i];
            }
        }

        while (end != -1) {
            //cout << end << " ";
            res.push_back(nums[end]);
            end = pre[end];
        }
        //cout << endl;

        return res;
    }
};
