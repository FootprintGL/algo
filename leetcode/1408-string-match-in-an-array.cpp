
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int i, j;

        /* 暴力算法 */

        /* 按单词长度排序 */
        sort(words.begin(), words.end(), [](string &s1, string &s2){return s1.size() < s2.size();});
        for (i = 0; i < words.size(); i++) {
            for (j = i + 1; j < words.size(); j++) {
                if (words[j].find(words[i]) != string::npos) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }

        return ans;
    }
};

class Solution {
public:
    /* 判断word2是否是word1的字串 */
    bool issub(string word1, string word2) {
        if (word1.length() < word2.length())
            return false;

        for (int i = 0; i < word1.length() - word2.length() + 1; i++) {
            if (word1[i] == word2[0] && word1.substr(i, word2.length()) == word2)
                return true;
        }

        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int i, j;

        /* 暴力算法 */
        for (i = 0; i < words.size(); i++) {
            for (j = i + 1; j < words.size(); j++) {
                if (words[i].length() >= words[j].length()) {
                    if (issub(words[i], words[j])) {
                        /* j是i的字串 */
                        ans.push_back(words[j]);
                        words.erase(words.begin() + j);
                        j--;
                    }
                } else {
                    if (issub(words[j], words[i])) {
                        /* i是j的字串 */
                        ans.push_back(words[i]);
                        break;
                    }
                }
            }
        }

        return ans;
    }
};
