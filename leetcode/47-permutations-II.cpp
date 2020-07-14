class Solution {
public:
    void dfs(vector<int> &nums, int len, int depth, vector<int> &path, vector<bool> &used, vector<vector<int>> &res) {
        if (depth == len) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < len; i++) {
            if (used[i])
                continue;
            /*
             * 回溯算法 - 同46全排列
             * 减枝条件 - 当前元素和前一个元素相同，并且前一个元素刚刚回溯重置
             */
            if (i >= 1 && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums, len, depth + 1, path, used, res);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        int len = nums.size();
        vector<bool> used(len, false);
        /* 先排序 - 把重复元素放在一起 */
        sort(nums.begin(), nums.end());

        dfs(nums, len, 0, path, used, res);

        return res;
    }
};
