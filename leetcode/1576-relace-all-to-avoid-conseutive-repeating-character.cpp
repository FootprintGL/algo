

class Solution {
public:
    char next(char c) {
        return c == 'z' ? 'a' : c + 1;
    }

    string modifyString(string s) {
        int n = s.length();

        if (n == 1)
            return "a";

        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                if (i == 0) {
                    if (s[i + 1] == '?')
                    /* 右边?，随便填 */
                        s[i] = 'a';
                    else
                    /* 右边字母，填不一样的 */
                        s[i] = next(s[i + 1]);
                } else if (i == n - 1) {
                    /* 左边肯定是字母，取下一个字母 */
                    s[i] = next(s[i - 1]);
                } else {
                    if (s[i + 1] == '?' || s[i - 1] == s[i + 1])
                    /* 右边为？或左右相等，取和左边不同 */
                        s[i] = next(s[i - 1]);
                    else if (s[i - 1] < s[i + 1]) {
                        if (s[i - 1] + 1 == s[i + 1])
                        /* 连续，取下一个 */
                            s[i] = next(s[i + 1]);
                        else
                        /* 不连续，去中间的 */
                            s[i] = next(s[i - 1]);
                    } else if (s[i - 1] > s[i + 1]) {
                        if (s[i + 1] + 1 == s[i - 1])
                        /* 连续，取下一个 */
                            s[i] = next(s[i - 1]);
                        else
                        /* 不连续，去中间的 */
                            s[i] = next(s[i + 1]);
                    }
                }
            }
        }

        return s;
    }
};
