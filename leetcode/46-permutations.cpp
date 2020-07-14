
class Solution {
public:
    void dfs(vector<int> &nums, int n, vector<int> &path, vector<bool> &used, vector<vector<int>> &res) {
        if (path.size() == n) {
            /* 保存结果 */
            res.push_back(path);
            return;
        }
        for (int i = 0; i < n; i++) {
            /* 过滤已经放过的数字 */
            if (used[i])
                continue;
            /* 放置数字 */
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums, n, path, used, res);
            /* 状态重置，准备放下一个数字 */
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        int n = nums.size();
        vector<bool> used(n, false);

        dfs(nums, n, path, used, res);

        return res;
    }
};



class Solution {
public:
    /* 检查元素是否已经加入到path中 */
    bool inpath(vector<int> &path, int num) {
        for (int i = 0; i < path.size(); i++)
            if(path[i] == num)
                return true;
        return false;
    }

    void dfs(vector<int> &nums, int n, vector<int> &path, vector<vector<int>> &res) {
        if (path.size() == n) {
            /* 保存结果 */
            res.push_back(path);
            return;
        }
        for (int i = 0; i < n; i++) {
            /* 过滤已经放过的数字 */
            if (inpath(path, nums[i]))
                continue;
            /* 放置数字 */
            path.push_back(nums[i]);
            dfs(nums, n, path, res);
            /* 还原现场，准备放下一个数字 */
            path.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        int n = nums.size();

        dfs(nums, n, path, res);

        return res;
    }
};
