

struct TrieNode {
    bool isend = false;
    TrieNode *next[26] = {nullptr};
};

class WordDictionary {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode *cur = root;
        for (auto &c : word) {
            if (cur->next[c - 'a'] == nullptr)
                cur->next[c - 'a'] = new TrieNode();
            cur = cur->next[c - 'a'];
        }
        cur->isend = true;
    }

    /* 递归 - 对'.'做特殊处理 */
    bool find(string &word, int start, TrieNode *cur) {
        if (start == word.size())
            return cur->isend;
        if (word[start] == '.') {
            for (int i = 0; i < 26; i++) {
                /* 遍历所有的下层指针，判断可能性 */
                if (cur->next[i] && find(word, start + 1, cur->next[i]))
                    return true;
            }
        } else {
            if (cur->next[word[start] - 'a'])
                return find(word, start + 1, cur->next[word[start] - 'a']);
        }
        return false;
    }

    bool search(string word) {
        return find(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
