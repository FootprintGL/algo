

class Solution {
public:
    vector<string> res;
    string tbl;

    void dfs(string &str, int start, int n) {
        if (start == n) {
            res.push_back(str);
            return;
        }

        for (int i = 0; i < 3; i++) {
            if (!str.empty() && str.back() == tbl[i])
                continue;
            str += tbl[i];
            dfs(str, start + 1, n);
            str.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        /* 回溯算法 */
        string str;
        tbl = "abc";
        dfs(str, 0, n);
        return k > res.size() ? "" : res[k - 1];
    }
};
