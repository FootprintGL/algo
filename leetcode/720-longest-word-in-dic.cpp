

class Solution {
public:
    string res;

    void dfs(string str, unordered_set<string> &dic) {
        if (!dic.count(str)) {
            return;
        }

        if (str.length() > res.length())
            res = str;

        for (int i = 0; i < 26; i++) {
            str.push_back(i + 'a');
            dfs(str, dic);
            str.pop_back();
        }
    }

    string longestWord(vector<string>& words) {
        unordered_set<string> dic;

        for (auto &word : words) {
            dic.insert(word);
        }

        for (int i = 0; i < 26; i++) {
            dfs(string(1, i + 'a'), dic);
        }

        return res;
    }
};
