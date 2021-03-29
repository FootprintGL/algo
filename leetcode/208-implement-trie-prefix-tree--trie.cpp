
struct TrieNode {
    bool isend = false;
    TrieNode *next[26] = {nullptr};
};

class Trie {
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = root;
        for (auto &c : word) {
            if (cur->next[c - 'a'] == nullptr)
                cur->next[c - 'a'] = new TrieNode();
            cur = cur->next[c - 'a'];
        }
        cur->isend = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *cur = root;
        for (auto &c : word) {
            if (cur->next[c - 'a'] == nullptr)
                return false;
            cur = cur->next[c - 'a'];
        }
        return cur->isend;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (auto &c : prefix) {
            if (cur->next[c - 'a'] == nullptr)
                return false;
            cur = cur->next[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */



class Trie {
public:
    bool isend;
    Trie* next[26];

    /** Initialize your data structure here. */
    Trie() {
        isend = false;
        memset(next, 0, sizeof(next));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        for (auto &c : word) {
            if (node->next[c - 'a'] == nullptr)
                node->next[c - 'a'] = new Trie();

            node = node->next[c - 'a'];
        }
        node->isend = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = this;
        for (auto &c : word) {
            node = node->next[c - 'a'];
            if (node == nullptr)
                return false;
        }
        return node->isend;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node = this;
        for (auto &c : prefix) {
            node = node->next[c - 'a'];
            if (node == nullptr)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
