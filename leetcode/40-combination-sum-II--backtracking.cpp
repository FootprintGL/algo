
class Solution {
public:
    vector<vector<int>> res;

    /* 回溯算法 */
    void dfs(vector<int> &candidates, vector<int> &cur, int start, int target) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1])
            /* 去重 - 跳过重复元素 */
                continue;

            if (candidates[i] <= target) {
                cur.push_back(candidates[i]);
                dfs(candidates, cur, i + 1, target - candidates[i]);
                /* 回溯 */
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        /* 去重 - 排序 */
        sort(candidates.begin(), candidates.end());
        dfs(candidates, cur, 0, target);
        return res;
    }
};
