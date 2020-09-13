

class Solution {
public:
    /* 通过第一个字母找到行号 */
    int findidx(vector<unordered_set<char>> &dic, char c) {
        int i;

        for (i = 0; i < dic.size(); i++) {
            if (dic[i].count(c))
                break;
        }

        return i;
    }

    /* 检查单词是否在某一行 */
    bool indic(unordered_set<char> &dic, string word) {
        for (auto c : word)
            if (dic.count(c) == 0)
                return false;

        return true;
    }

    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        string s[3] = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};

        /* 三行字母放入哈希表 */
        vector<unordered_set<char>> dic(3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < s[i].length(); j++) {
                dic[i].insert(s[i][j]);
            }
        }

        for (auto word : words) {
            int idx = findidx(dic, word[0]);

            if (indic(dic[idx], word))
                res.push_back(word);
        }

        return res;
    }
};
