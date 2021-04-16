

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        /*
         * ans[i] = nums[i] - nums[0] + ... + nums[i] - nums[i - 1] + nums[i + 1] - nums[i] + ... + nums[n - 1] - nums[i]
         *        = i * nums[i] - sum(0 ~ i - 1) + sum(i + 1 ~ n - 1) - (n - i - 1) * nums[i]
         * 计算前缀和和后缀和加速计算
         */
        int n = nums.size();
        vector<int> pre(n, 0);
        vector<int> post(n, 0);
        vector<int> res(n, 0);

        /* 前缀和 */
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }

        /* 后缀和 */
        for (int i = n - 2; i >= 0; i--) {
            post[i] = post[i + 1] + nums[i + 1];
        }

        /* 构建结果 */
        for (int i = 0; i < n; i++) {
            res[i] = i * nums[i] - pre[i] + post[i] - (n - i - 1) * nums[i];
        }

        return res;
    }
};
