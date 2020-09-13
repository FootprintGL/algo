
class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int> &cur, int k, int n, int start) {
        //cout << k << " " << n << " " << start << endl;
        if (k == 0 && n == 0) {
            res.push_back(cur);
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (i > n)
                break;
            cur.push_back(i);
            dfs(cur, k - 1, n - i, i + 1);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur;
        dfs(cur, k, n, 1);
        return res;
    }
};
