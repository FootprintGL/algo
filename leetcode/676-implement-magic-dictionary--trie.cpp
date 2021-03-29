

struct TrieNode {
    bool isend = false;
    TrieNode *next[26] = {nullptr};
};

class MagicDictionary {
    TrieNode *root;
    /* 标记是否已经替换过 */
    bool replaced = false;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode();
    }

    void buildDict(vector<string> dictionary) {
        for (auto &word : dictionary) {
            TrieNode *cur = root;
            for (auto &c : word) {
                if (cur->next[c - 'a'] == nullptr)
                    cur->next[c - 'a'] = new TrieNode();
                cur = cur->next[c - 'a'];
            }
            cur->isend = true;
        }
    }

    /* 只能替换一个字符 */
    bool find(string &word, TrieNode *cur, int start) {
        if (start == word.size())
        /* 替换过一个字母 */
            return cur->isend && replaced;

        char c = word[start];
        /* 直接搜索 */
        if (cur->next[c - 'a'] && find(word, cur->next[c - 'a'], start + 1))
            return true;

        if (!replaced) {
            /* 没有替换过 - 替换当前字符 */
            replaced = true;
            for (int i = 0; i < 26; i++) {
                if (i != c - 'a' && cur->next[i]) {
                    if(find(word, cur->next[i], start + 1)) {
                        replaced = false;
                        return true;
                    }
                }
            }
            /* 回溯 */
            replaced = false;
        }

        return false;
    }

    bool search(string searchWord) {
        return find(searchWord, root, 0);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
