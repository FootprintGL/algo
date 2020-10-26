class Solution {
public:
    vector<string> res;

    void dump(vector<bool> &visited) {
        for (auto v : visited)
            cout << v << " ";
        cout << endl;
    }

    void dfs(string &s, int len, int start, string &cur, vector<bool> &visited) {
        //cout << start << " " << cur << endl;
        //dump(visited);
        //cout << endl;
        if (start == len) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < len; i++) {
            if (visited[i])
                continue;
	    /* visited[i - 1] == true也能通过，但效率稍低 */
            if (i > 0 && s[i] == s[i - 1] && visited[i - 1] == false)
                continue;
            visited[i] = true;
            cur += s[i];
            dfs(s, len, start + 1, cur, visited);
            cur.pop_back();
            visited[i] = false;
        }
    }

    vector<string> permutation(string S) {
        /* 回溯算法 */
        string cur;
        vector<bool> visited(S.length(), false);
        sort(S.begin(), S.end());
        //cout << S << endl;
        dfs(S, S.length(), 0, cur, visited);
        return res;
    }
};



class Solution {
public:
    vector<string> res;

    void dump(vector<bool> &visited) {
        for (auto v : visited)
            cout << v << " ";
        cout << endl;
    }

    void dfs(string &s, int len, int start, string &cur, vector<bool> &visited) {
        //cout << start << " " << cur << endl;
        //dump(visited);
        //cout << endl;
        if (start == len) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < len; i++) {
            if (visited[i])
                continue;
            if (i > 0 && s[i] == s[i - 1] && visited[i - 1] == true)
                continue;
            visited[i] = true;
            cur += s[i];
            dfs(s, len, start + 1, cur, visited);
            cur.pop_back();
            visited[i] = false;
        }
    }

    vector<string> permutation(string S) {
        /* 回溯算法 */
        string cur;
        vector<bool> visited(S.length(), false);
        sort(S.begin(), S.end());
        //cout << S << endl;
        dfs(S, S.length(), 0, cur, visited);
        return res;
    }
};



class Solution {
public:
    vector<string> res;
    /* 哈希表去重 */
    unordered_set<string> tbl;

    void dfs(string &s, int len, int start, string &cur, vector<bool> &visited) {
        if (start == len) {
            if (tbl.count(cur) == 0) {
                tbl.insert(cur);
            }
            return;
        }
        for (int i = 0; i < len; i++) {
            if (visited[i])
                continue;
            visited[i] = true;
            cur += s[i];
            dfs(s, len, start + 1, cur, visited);
            cur.pop_back();
            visited[i] = false;
        }
    }

    vector<string> permutation(string S) {
        /* 回溯算法 */
        string cur;
        vector<bool> visited(S.length(), false);
        dfs(S, S.length(), 0, cur, visited);
        for (auto &t : tbl)
            res.push_back(t);
        return res;
    }
};
