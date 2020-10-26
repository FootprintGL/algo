


class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        /* 逆向思维 - 单词转换成数字串 */
        vector<string> res;
        string key = "22233344455566677778889999";

        for (auto &word : words) {
            string dec;
            for (auto &c : word)
                dec.push_back(key[c - 'a']);
            if (dec == num)
                res.push_back(word);
        }

        return res;
    }
};



/* 字典树加速匹配 */
class trienode {
public:
    bool end;
    string val;
    trienode *child[26];
    trienode() {
        for (auto &c : child)
            c = NULL;

        end = false;
    }
};

class trie {
public:
    trienode *root;

    trie() {
        root = new trienode();
    }

    void insert(string word) {
        trienode *cur = root;
        //cout << word << " " << root << endl;
        for (auto &c : word) {
            int t = c - 'a';
            if (cur->child[t] == NULL) {
                cur->child[t] = new trienode();
            }
            cur = cur->child[t];
        }
        cur->val = word;
        cur->end = true;
    }
};

class Solution {
public:
    vector<string> res;
    string board[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };

    void dfs(string &num, int n, int start, trienode *cur) {
        //cout << start << " " << n << " " << endl;
        if (start == n)
            return;

        string option = board[num[start] - '0'];
        for (auto &c : option) {
            trienode *tmp = cur->child[c - 'a'];
            if (tmp == NULL)
                continue;
            if (tmp->end) {
                res.push_back(tmp->val);
            } else {
                dfs(num, n, start + 1, tmp);
            }
        }
    }

    vector<string> getValidT9Words(string num, vector<string>& words) {
        trie t;
        trienode *cur = t.root;

        for (auto &word : words)
            t.insert(word);

        /* 字典树加速匹配 */
        dfs(num, num.length(), 0, cur);

        return res;
    }
};



/* 超时 */
class Solution {
public:
    unordered_set<string> tbl;
    vector<string> res;
    string board[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };

    void dfs(string &num, int n, int start, string &cur) {
        //cout << start << " " << n << " " << cur << endl;
        if (start == n) {
            if (tbl.count(cur))
                res.push_back(cur);
            return;
        }

        string option = board[num[start] - '0'];
        //cout << num[start] << " " << option << " " << (num[start] - '0') << endl;
        for (int i = 0; i < option.length(); i++) {
            cur += option[i];
            dfs(num, n, start + 1, cur);
            /* 回溯 */
            cur.pop_back();
        }
    }

    vector<string> getValidT9Words(string num, vector<string>& words) {
        string cur;

        for (auto &word : words)
            tbl.insert(word);
        /* 回溯算法 */
        dfs(num, num.length(), 0, cur);

        return res;
    }
};
