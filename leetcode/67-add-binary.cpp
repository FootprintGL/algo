


class Solution {
public:

    /* 二进制加法: c - 表示进位 */
    char helper(char a, char b, char &c) {
        char res;

        if (a == '0') {
            if (b == '0'){
                /* a = 0, b = 0 */
                res = c;
                c = '0';
            } else {
                if (c == '0') {
                    /* a = 0, b = 1, c = 0 */
                    res = '1';
                    c = '0';
                } else {
                    /* a = 0, b = 1, c = 1 */
                    c = '1';
                    res = '0';
                }
            }
        }

        if (a == '1') {
            if (b == '0') {
                if (c == '0') {
                    /* a = 1, b = 0, c = 0 */
                    res = '1';
                    c = '0';
                } else {
                    /* a = 1, b = 1, c = 0 */
                    c = '1';
                    res = '0';
                }
            } else {
                if (c == '0') {
                    /* a = 1, b = 1, c = 0 */
                    c = '1';
                    res = '0';
                } else {
                    /* a = 1, b = 1, c = 1 */
                    c = '1';
                    res = '1';
                }
            }
        }

        return res;
    }

    string addBinary(string a, string b) {
        char c = '0';
        int la = a.size();
        int lb = b.size();
        int l = max(la, lb);
        string s(l + 1, ' ');
        int i;

        /* 注意s的长度为l + 1, 存储位置偏移了一位 a[la - i - 1] <-> s[la - i] */
        if (la < lb) {
            for (i = 0; i < lb; i++) {
                if (i < la)
                    s[lb - i] = helper(a[la - i - 1], b[lb - i - 1], c);
                else
                    s[lb - i] = helper('0', b[lb - i - 1], c);
            }
        } else {
            for (i = 0; i < la; i++) {
                if (i < lb) {
                    s[la - i] = helper(a[la - i - 1], b[lb - i - 1], c);
                }
                else
                    s[la - i] = helper('0', a[la - i - 1], c);
            }
        }

        if (c == '1') {
            /* 写入进位符 */
            s[0] = c;
            return s;
        } else {
            /* 没有进位 - 截掉第一个字符 */
            return s.substr(1, l);
        }
    }
};

