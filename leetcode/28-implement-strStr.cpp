

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        int start = 0, end = 0;

        if (n == 0)
            return 0;

        if (m == 0 || m < n)
            return -1;

        /* 双指针 */
        while (start <= m - n) {
            /* 匹配地一个字符 */
            while (start <= m - n && haystack[start] != needle[0])
                start++;

            /* 匹配不到 - 退出 */
            if (start > m - n)
                break;

            /* 匹配到第一个字符，开始匹配整个字符串 */
            end = start;

            while (end < start + n && haystack[end] == needle[end - start])
                end++;
            cout << start << " - " << end << " " << n << endl;
            /* 匹配到整个字符串，返回结果 */
            if (end == start + n)
                return start;

            /* 为匹配到整个字符串，继续匹配第一个字符 */
            start++;
        }

        return -1;
    }
};
