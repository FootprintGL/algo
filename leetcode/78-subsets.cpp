class Solution {
public:
    void dfs(vector<int> &nums, int len, int depth, vector<int> &path, vector<vector<int>> &res) {
        res.push_back(path);
        if (depth == len)
            return;
        for (int i = depth; i < len; i++) {
            path.push_back(nums[i]);
            dfs(nums, len, i + 1, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        int len = nums.size();
        /* 
         * 回溯算法 - 同77组合
         * 不过这里要返回所有节点，77只返回叶子节点
         */    
        dfs(nums, len, 0, path, res);

        return res;
    }
};
