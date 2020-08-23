

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
