

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    /* 
     * 回溯算法
     * 每一个元素可以选择，也可以不选择
     * 求递增子序列，只有nums[cur] >= last是才做选择
     * nums[cur] == last时:
     * 1. 两个都选择
     * 2. 选择last, 不选择cur
     * 3. 不选择last，选择cur
     * 4. 不选择last, 不选择cur
     * 2,3情况是等价的，取第3种情况。
     * 避免重复，只有在cur不等于last是才不选last
     */
    void dfs(int cur, int last, vector<int> &nums) {
        if (cur == nums.size()) {
            if (temp.size() > 1)
                ans.push_back(temp);
            return;
        }
        if (nums[cur] >= last) {
            temp.push_back(nums[cur]);
            dfs(cur + 1, nums[cur], nums);
            temp.pop_back();
        }
        if (nums[cur] != last) {
            dfs(cur + 1, last, nums);
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0, -101, nums);
        return ans;
    }
};
