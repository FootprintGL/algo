
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        /*
         * 构造双倍字符串
         * s = nx
         * s + s = 2nx
         * 去掉首位字母破坏开头和结尾的字串，剩下2(n - 2)个字串
         * 如果s在(s + s)(1, -1)中，则有2n - 2 >= n, 则有n >= 2
         * 如果s不在(s + s)(1, -1)中，则有2n - 2 < n, 则有n < 2, 不能有多个重复字串构成
         */
        string t = s + s;
        return t.substr(1, t.length() - 2).find(s) != -1;
    }
};

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        int start = 0, end, i, j;
        bool flag = true;

        /* 搜索以s[0]开始的字串，判断是否相等 */
        for (i = 1; i < len; i++) {
            if (s[i] == s[0]) {
                if (len % (i))
                    continue;
                for (j = i; j < len; j = j + i) {
                    /* 检查字串 */
                    if (s.compare(0, i, s.substr(j, i)) != 0) {
                        /* substr(0, i)不是要找重复字串，继续搜索 */
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    /* 找到重复字串 */
                    return true;
                else
                    /* substr(0, i)不是要找重复字串，继续搜索 */
                    flag = true;
            }
        }

        return false;
    }
};
