
class Solution {
public:
    void dfs(int n, int k, int start, vector<int> &path, vector<vector<int>> &res) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
	/* 当i > n - (k - path.size()) + 1时，已经没有k - path.size()个数可供放置 */
        for (int i = start; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            dfs(n, k, i + 1, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;

        dfs(n, k, 1, path, res);

        return res;
    }
};

class Solution {
public:
    void dfs(int n, int k, int start, vector<int> &path, vector<vector<int>> &res) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = start; i <= n; i++) {
            path.push_back(i);
            dfs(n, k, i + 1, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;

        dfs(n, k, 1, path, res);

        return res;
    }
};
