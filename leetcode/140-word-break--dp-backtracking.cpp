



class Solution {
public:
    vector<string> res;
    vector<string> path;

    void dump(vector<string> &t) {
        for (auto &s : t)
            cout << s << endl;
    }

    /* s[0:len)可以拆分成wordSet中的单词，把递归求解的结果放入res中 */
    void dfs(string &s, int len, unordered_set<string> &tbl, vector<bool> &dp) {
        /*
        cout << s << " " << len << endl;
        dump(path);
        cout << endl;
        dump(res);
        cout << endl << endl;
        */
        if (len == 0) {
            /* 构建结果 */
            string s;
            for (int i = path.size() - 1; i >= 0; i--) {
                s += path[i];
                if (i != 0)
                /* 最后一个不需要加空格 */
                    s += ' ';
            }
            /* 保存结果 */
            res.push_back(s);
            return;
        }

        for (int i = len - 1; i >= 0; i--) {
            string suffix = s.substr(i, len - i);
            if (tbl.count(suffix) && dp[i]) {
                path.push_back(suffix);
                dfs(s, i, tbl, dp);
                /* 回溯 */
                path.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        /* 动态规划 + 回溯 */
        unordered_set<string> tbl(wordDict.begin(), wordDict.end());
        int len = s.length();
        int i, j;

        /* 1. 预处理 - 动态规划数组记录是否有解 */
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for (i = 1; i < len + 1; i++) {
            for (j = 0; j < i; j++) {
                if (tbl.count(s.substr(j, i - j)) && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

/*
        for (auto t : dp)
            cout << t << " ";
        cout << endl;
*/
        if (dp[len]) {
            /* 有解 */
            dfs(s, len, tbl, dp);
        }

        return res;
    }
};
