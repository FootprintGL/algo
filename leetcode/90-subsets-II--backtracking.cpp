

class Solution {
public:
    vector<vector<int>> res;
    int n;

    void dfs(vector<int> &nums, int start, vector<int> &path) {
        res.push_back(path);
        for (int i = start; i < n; i++) {
            if (i > start && nums[i] == nums[i - 1])
            /* 如果和前一个数相同，跳过 */
                continue;
            path.push_back(nums[i]);
            dfs(nums, i + 1, path);
            /* 回溯 */
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        /* 回溯 */
        vector<int> path;
        n = nums.size();
        /* 先排序 */
        sort(nums.begin(), nums.end());
        dfs(nums, 0, path);
        return res;
    }
};
