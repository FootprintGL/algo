

class Solution {
public:
    bool helper(string &word, string &pattern) {
        /*
         * 哈希表保存字母到字母的映射关系，如果一个字母映射到不同字母，
         * 则不是同构字符串, 需要s->t, t->s分别检查
         */
        unordered_map<char, char> tbl;

        for (int i = 0; i < word.length(); i++) {
            if (tbl.count(word[i])) {
                if (tbl[word[i]] != pattern[i])
                    return false;
            } else {
                tbl[word[i]] = pattern[i];
            }
        }

        return true;
    }

    /* 检查word和pattern是否匹配 */
    bool match(string &word, string &pattern) {
        if (word.length() != pattern.length())
            return false;

        return helper(word, pattern) && helper(pattern, word);
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;

        for (auto &word : words)
            if (match(word, pattern))
                res.push_back(word);

        return res;
    }
};
