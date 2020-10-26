

class WordsFrequency {
public:
    unordered_map<string, int> tbl;

    WordsFrequency(vector<string>& book) {
        for (auto &word : book)
            tbl[word]++;
    }
    /* 哈希表 */
    int get(string word) {
        if(tbl.count(word)) {
            return tbl[word];
        } else {
            return 0;
        }
    }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */
