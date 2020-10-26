

class Solution {
public:
    vector<string> res;

    void dfs(string &s, int len, int start, string &cur, vector<bool> &visited) {
        //cout << start << " " << cur << endl;
        if (start == len) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < len; i++) {
            if (visited[i])
                continue;
            visited[i] = true;
            cur += s[i];
            dfs(s, len, start + 1, cur, visited);
            /* 回溯 */
            cur.pop_back();
            visited[i] = false;
        }
    }

    vector<string> permutation(string S) {
        /* 回溯算法 */
        int len = S.length();
        string cur;
        vector<bool> visited(len, false);
        dfs(S, len, 0, cur, visited);
        return res;
    }
};
