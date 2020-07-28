



class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector(n + 2, 0));
        int i, j, k, len;

        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        /*
         * 动态规划
         * dp[i][j]表示戳破(i,j)气球能获得的最大硬币数量
         * 假设最后一个戳破的气球为k，则
         * dp[i][j] = max(dp[i][k - 1] + dp[k + 1][j] + nums[i] * nums[k] * nums[j]) (k: i -> j)
         * dp[i][i] = 0,为方便，在首位插入1表示第-1号和第n号气球，假气球不能被戳破
         * 返回dp[1][n]
         */
        for (len = 1; len <= n; len++) {
            for (i = 1; i <= n - len + 1; i++) {
                j = i + len - 1;
                for (k = i; k <= j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j + 1]);
                }
            }
        }

        return dp[1][n];
    }
};






/* 超时 - [35,16,83,87,84,59,48,41,20,54] */
class Solution {
public:
    int ans;

    void helper(vector<int> &nums, int &res) {
        if (nums.size() == 2) {
            ans = max(ans, res);
            return;
        }
        for (int i = 1; i <= nums.size() - 2; i++) {
            int tmp = nums[i];
            res += nums[i - 1] * nums[i] * nums[i + 1];
            nums.erase(nums.begin() + i);
            helper(nums, res);
            nums.insert(nums.begin() + i, tmp);
            res -= nums[i - 1] * nums[i] * nums[i + 1];
        }
    }

    int maxCoins(vector<int>& nums) {
        int res = 0;
        ans = 0;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        /*
         * 回溯算法
         * 数组首尾插入1模拟假气球，假气球不能被戳破
         */
        helper(nums, res);

        return ans;
    }
};
