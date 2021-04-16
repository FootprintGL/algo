


/* 前缀树 */
class TrieNode {
public:
    bool iskey;
    int val;
    vector<TrieNode *>children;
    TrieNode() : iskey(false), val(0),children(26, nullptr) {}
};

class MapSum {
public:
    TrieNode *root;

    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        TrieNode *cur = root;
        for (auto &c : key) {
            if (cur->children[c - 'a'] == nullptr)
                cur->children[c - 'a'] = new TrieNode();
            cur = cur->children[c - 'a'];
        }
        cur->iskey = true;
        cur->val = val;
    }

    /* 递归统计从cur开始的key值总和 */
    int helper(TrieNode *cur) {
        int res = 0;

        if (cur->iskey)
            res += cur->val;

        for (int i = 0; i < 26; i++) {
            if (cur->children[i])
                res += helper(cur->children[i]);
        }

        return res;
    }

    int sum(string prefix) {
        int res = 0;
        TrieNode *cur = root;
        for (auto &c : prefix) {
            if (cur->children[c - 'a'])
                cur = cur->children[c - 'a'];
            else
                return 0;
        }

        return helper(cur);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
