

/* 字典树节点 */
class trienode {
public:
    int index;
    trienode *child[26];
    trienode() : index(-1) {
        for (auto &c : child)
            c = nullptr;
    }
};

/* 字典树 */
class trie {
public:
    trienode *root;
    trie() {
        root = new trienode();
    }

    /* 插入 */
    void insert (string &word, int index) {
        trienode *p = root;
        for (auto &c : word) {
            int t = c - 'a';
            if (!p->child[t])
                p->child[t] = new trienode();
            p = p->child[t];
        }
        p->index = index;
    }

    /* 搜索 */
    void search(string &word, int index, vector<vector<int>> &res) {
        trienode *p = root;

        for (auto &c : word) {
            trienode* t = p->child[c - 'a'];

            if (!t)
                break;
            if (t->index != -1)
                res[t->index].push_back(index);
            p = t;
        }
    }
};

class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        int m = big.size(), n = smalls.size(), i;
        vector<vector<int>> res(n);
        trie t;

        /* 构建字典树 */
        for (i = 0; i < n; i++) {
            t.insert(smalls[i], i);
        }

        /* 遍历big所有后缀，在字典树中查找 */
        for (i = 0; i < m; i++) {
            string word = big.substr(i, m - i);
            t.search(word, i, res);
        }

        return res;
    }
};
