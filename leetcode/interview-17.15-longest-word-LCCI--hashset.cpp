


/* 按长度排序，如果长度相等，则字典序小的在前 */
bool mycompare(string &w1, string &w2) {
    int len1 = w1.length(), len2 = w2.length();
    return len1 == len2 ? w1 < w2 : len1 > len2;
}

/* 检测word能否由其他单词构成 */
bool validword(unordered_set<string> &tbl, string word) {
    int n = word.length();

    //cout << word << " " << n << endl;
    if (n == 0)
        return true;

    for (int i = 1; i <= n; i++) {
        if (tbl.count(word.substr(0, i)) && validword(tbl, word.substr(i)))
            return true;
    }

    return false;
}

class Solution {
public:
    string longestWord(vector<string>& words) {
        /* 哈希表 */
        string res;
        unordered_set<string> tbl;
        int maxlen = 0, i;

        for (auto &word : words)
            tbl.insert(word);

        /* 按字符串长度排序 */
        sort(words.begin(), words.end(), mycompare);

        //for (auto word : words)
            //cout << word << endl;

        for (i = 0; i < words.size(); i++) {
            /* 移出当前搜索word */
            tbl.erase(words[i]);
            if (validword(tbl, words[i]))
                return words[i];
            /* 放回当前搜索word */
            tbl.insert(words[i]);
        }

        return res;
    }
};
