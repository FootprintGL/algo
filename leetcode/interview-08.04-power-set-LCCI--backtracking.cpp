

class Solution {
public:
    vector<vector<int>> res;

    void dump(vector<int> &cur) {
        for (auto &c : cur)
            cout << c << " ";
        cout << endl;
    }

    void dfs(vector<int> &nums, int n, int start, vector<int> &cur) {
        //cout << start << " - " << n << endl;
        //dump(cur);
        //cout << endl;

        res.push_back(cur);
        if (start == n)
            return;

        for (int i = start; i < n; i++) {
            cur.push_back(nums[i]);
            dfs(nums, n, i + 1, cur);
            cur.pop_back();
        }
    }

    /* 回溯算法 */
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        dfs(nums, nums.size(), 0, cur);
        return res;
    }
};
