

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        /*
         * 动态规划 - 0/1背包问题
         * 所有符号为正的数总和设为一个背包的容量x，所有符号为负的数总和设为一个背包的容量y
         * 在给定的背包中有多少中方法装满，x + y = sum, x - y = S -> x = (S + sum)/2
         * 转换为背包问题：给定一个数组和一个容量为x的背包，求有多少种方式让背包填满
         * dp[i][j] - 前i个元素能拼出j的方法
         * dp[i][j] = sum(dp[i - 1][j - nums[i]]), i = 0 -> n, j >= nums[i]
         * 结果为dp[n][target]
         * 结果只和前一行有关，可压缩为成一维
         */
        int n = nums.size();
        /* 定义为int型会溢出 -  [2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53] 2147483647 */
        //int sum = 0;
        long sum = 0;
        int i, j;

        for (i = 0; i < n; i++)
            sum += nums[i];
        
        if ((S + sum) % 2 == 1 || S > sum)
            return 0;

        int target = (sum + S) / 2;
        vector<int> dp(target + 1, 0);
        /* 背包为0，一个都不选为一种解决方案 */
        dp[0] = 1;
        for (i = 0; i < n; i++) {
            for (j = target; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[target];
    }
};


class Solution {
public:
    int cnt;
    /* 逐个添加+/-号搜索结果 */
    void helper(vector<int> &nums, int start, int sum, int s) {
        if (start == nums.size()) {
            if (sum == s)
                cnt++;
            return;
        }
        helper(nums, start + 1, sum + nums[start], s);
        helper(nums, start + 1, sum - nums[start], s);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        cnt = 0;
        helper(nums, 0, 0, S);
        return cnt;
    }
};
