

class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int> &candidates, vector<int> &cur, int start, int target) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target)
                continue;
            cur.push_back(candidates[i]);
            /* 每次之从选择元素以及后面的元素中选择 */
            dfs(candidates, cur, i, target - candidates[i]);
            /* 回溯 */
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        dfs(candidates, cur, 0, target);
        return res;
    }
};
