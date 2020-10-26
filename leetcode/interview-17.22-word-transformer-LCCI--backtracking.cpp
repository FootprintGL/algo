

class Solution {
public:
    vector<string> res;
    string letter = "abcdefghijklmnopqrstuvwxyz";

    bool dfs(unordered_map<string, bool> &dic, string curword, string &endWord, int len) {
        dic[curword] = true;
        res.push_back(curword);
        if (curword == endWord)
            return true;

        /* 每个位置替换成不同字符检查是否在字典中 */
        for (int i = 0; i < len; i++) {
            char c = curword[i];
            for (int j = 0; j < 26; j++) {
                if (letter[j] == c)
                    continue;
                curword[i] = letter[j];
                if (dic.count(curword) && dic[curword] == false) {
                    if (dfs(dic, curword, endWord, len))
                        return true;
                }
            }
            curword[i] = c;
        }
        /* 回溯 */
        res.pop_back();

        return false;
    }

    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> dic;

        /* DFS回溯算法 */
        for (auto &word : wordList)
            dic[word] = false;

        if (dic.count(endWord) == 0)
            return res;

        dfs(dic, beginWord, endWord, beginWord.length());

        return res;
    }
};
