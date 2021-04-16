



class Solution {
public:
    struct trienode {
        int end = 0;
        trienode *next[26] = {nullptr};
    };

    struct trienode *root;

    int countSubstrings(string s, string t) {
        /*
         * 取s的非空字串，替换一个字符，看t中有多少个字串可以匹配
         * 字典树加速匹配
         */
        root = new trienode();
        int res = 0;

        /* s字串构建字典树 */
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                auto cur = root;
                for (int k = i; k <= j; k++) {
                    if (cur->next[s[k] - 'a'] == nullptr)
                        cur->next[s[k] - 'a'] = new trienode();
                    cur = cur->next[s[k] - 'a'];
                }
                cur->end++;
            }
        }

        /* s的字串，替换一个字符在字典树中匹配 */
        for (int i = 0; i < t.length(); i++) {
            for (int j = i; j < t.length(); j++) {
                for (int k = i; k <= j; k++) {
                    char cc = t[k];
                    for (int c = 0; c < 26; c++) {
                        if (t[k] == c + 'a')
                            continue;
                        /* 替换一个字符后去字典树里搜索 */
                        t[k] = c + 'a';
                        res += match(t, i, j);
                        t[k] = cc;
                    }
                }
            }
        }

        return res;
    }

    int match(string &t, int i, int j) {
        /* 在字典树中搜索t:[i,j] */
        auto cur = root;
        for (int k = i; k <= j; k++) {
            if (!cur->next[t[k] - 'a'])
                return 0;
            cur = cur->next[t[k] - 'a'];
        }
        return cur->end;
    }
};
