


class Solution {
public:
    vector<string> res;

    void dfs(string &s, int len, string &path, vector<bool> &visited) {
        if (path.length() == len) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < len; i++) {
            if (visited[i])
                continue;
	    /* 如果有多个相同字符，必须排着使用如果前面还没用就跳过 */
            if (i > 0 && s[i] == s[i - 1] && !visited[i - 1])
                continue;
            path += s[i];
            visited[i] = true;
            dfs(s, len, path, visited);
            visited[i] = false;
            path.pop_back();
        }
    }

    vector<string> permutation(string s) {
        string path;
        int len = s.length();
        if (len < 2)
            return {s};
        vector<bool> visited(len, false);
        /* 排序方便去重 */
        sort(s.begin(), s.end());
        dfs(s, len, path, visited);
        return res;
    }
};
