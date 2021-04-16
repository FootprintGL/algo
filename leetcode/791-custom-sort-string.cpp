

/* 字符在S中的位置index */
int pos[26];

class Solution {
public:
    string customSortString(string S, string T) {
        /* 初始化为最大26 */
        for (int i = 0; i < 26; i++)
            pos[i] = 26;

        for (int i = 0; i < S.length(); i++)
            pos[S[i] - 'a'] = i;

        sort(T.begin(), T.end(), [](char &c1, char &c2) {
            return pos[c1 - 'a'] < pos[c2 - 'a'];
        });

        return T;
    }
};
