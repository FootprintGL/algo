

/* 前缀树 */
class TrieNode {
public:
    string word;
    TrieNode *children[26];
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        /* 构造前缀树 */
        TrieNode *trie = new TrieNode();
        TrieNode *cur;
        for (auto &w : dictionary) {
            cur = trie;
            for (auto &c : w) {
                if (cur->children[c - 'a'] == nullptr)
                    cur->children[c - 'a'] = new TrieNode();
                cur = cur->children[c - 'a'];
            }
            cur->word = w;
        }

        /* istringstream分割单词 */
        istringstream iss(sentence);
        vector<string> words;
        string word;
        while(iss >> word)
            words.push_back(word);

        /* 逐个单词进行检查 */
        string res, prefix;
        for (auto &w : words) {
            cur = trie;
            for (auto &c : w) {
                if (cur->children[c - 'a'] == NULL || cur->word.size())
                    break;
                cur = cur->children[c - 'a'];
            }

            if (res.length() != 0)
                res += ' ';
            res += cur->word.size() ? cur->word : w;
        }

        return res;
    }
};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        /* 哈希表存放词根，检查句子中前缀是否包含词根 */

        unordered_set<string> roots;
        for (auto &w : dictionary)
            roots.insert(w);

        /* istringstream分割单词 */
        istringstream iss(sentence);
        vector<string> words;
        string word;
        while(iss >> word)
            words.push_back(word);

        /* 逐个单词进行检查 */
        string res, prefix;
        for (auto &w : words) {
            for (int i = 1; i <= w.length(); i++) {
                prefix = w.substr(0, i);
                if (roots.count(prefix))
                    break;
            }
            if (res.length() != 0)
                res += ' ';
            res += prefix;
        }

        return res;
    }
};
