

class Trie {
public:
    Trie *next[26] = {};
    bool end;

    Trie() {
        end = false;
    }
    void insert(string s) {
        Trie *cur = this;
        int i;
        int id;

        for (i = s.length() - 1; i >= 0; i--) {
            id = s[i] - 'a';
            if (!cur->next[id])
                cur->next[id] = new Trie();
            cur = cur->next[id];
        }
        cur->end = true;
    }
};


class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        class Trie *dic = new Trie(), *cur;
        int len = sentence.size();
        vector<int> dp(len + 1, 0);
        int id;
        int i, j;
        /*
         * 动态规划
         * dp[i]表示前i个字母最少未识别的字符数
         * dp[i] = dp[i - 1] + 1 -> 如果字典没有以sentence[i]结尾的
         * dp[i] = dp[j] -> 如果有[j, i - 1]是字典里的单词
         * 字典树加速字符串查找
         */
        /* 后缀匹配 - 单词表中单词逆序放入字典树dic */
        for (i = 0; i < dictionary.size(); i++)
            dic->insert(dictionary[i]);
        
        dp[0] = 0;
        for (i = 1; i <= len; i++) {
            /* 默认假设sentence[i]不在字典中 */
            dp[i] = dp[i - 1] + 1;
            cur = dic;
            for (j = i; j >= 1; j--) {
                id = sentence[j - 1] - 'a';
                if (cur->next[id] == NULL) {
                    break;
                } else if (cur->next[id]->end == true){
                    if (dp[j - 1] < dp[i])
                            dp[i] = dp[j - 1];;
                }
                if (dp[i] == 0)
                    break;
                cur = cur->next[id];
            }
        }

        return dp[len];
    }
};


class Solution {
public:


    int respace(vector<string>& dictionary, string sentence) {
        set<string> dic;
        int len = sentence.size();
        vector<int> dp(len + 1, 0);
        int i, j;

        /*
         * 动态规划 - 暴力循环 （超时555）
         * dp[i]表示前i个字母最少未识别的字符数
         * dp[i] = dp[i - 1] + 1 -> 如果字典没有以sentence[i]结尾的
         * dp[i] = dp[j] -> 如果有[j, i - 1]是字典里的单词
         */
        /* 单词表中单词放入哈希表dic */
        for (i = 0; i < dictionary.size(); i++)
            dic.insert(dictionary[i]);

        dp[0] = 0;
        for (i = 1; i <= len; i++) {
            /* 默认假设sentence[i]不在字典中 */
            dp[i] = dp[i - 1] + 1;
            for (j = 0; j < i; j++) {
                if (dic.find(sentence.substr(j, i - j)) != dic.end()) {
                    /* [j, i - 1]字串在字典中 */
                    if (dp[j] < dp[i]) {
                        dp[i] = dp[j];
                        if (dp[i] == 0)
                            break;
                    }
                }
            }
        }

        return dp[len];
    }
};
