



class Solution {
public:
    vector<vector<string>> res;
    int len;

    /* 检查[start, end]的字串是否为回文 */
    bool ispalindrome(string &s, int start, int end) {
        int l = start, r = end;
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void dfs(string &s, int start, vector<string> &path) {
        if (start == len) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < len; i++) {
            if (!ispalindrome(s, start, i))
                /* 剪枝 - 不是回文 */
                continue;
            path.push_back(s.substr(start, i - start + 1));
            /* 继续处理后续子串 */
            dfs(s, i + 1, path);
            /* 回溯 */
            path.pop_back();
        }

    }

    vector<vector<string>> partition(string s) {
        /*
         * 回溯算法
         */
        len = s.length();
        vector<string> path;
        dfs(s, 0, path);
        return res;
    }
};
