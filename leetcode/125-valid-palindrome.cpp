class Solution {
public:
    bool isdigital(char c) {
        return (c >= '0' && c <= '9');
    }

    bool isletter (char c) {
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    }

    char tolower(char c) {
        if (c >= 'a' && c <= 'z')
            return c;
        else
            return c + ('a' - 'A');
    }

    bool isPalindrome(string s) {
        int len = s.size();
        int i = 0, j = len - 1;

        /* 特殊情况 - 可以省略: 当len为0时，j是-1，主循环不会走进去 */
        if (len == 0) {
            return true;
        }

        while (i < j) {
            while (!isdigital(s[i]) && !isletter(s[i])) {
                i++;
                
                if (i == j) {
                    /* 如果字符串没有数字和字母，防止越界 */
                    return true;
                }
            };
            while (!isdigital(s[j]) && !isletter(s[j])) {
                j--;
                if (i == j) {
                    /* 如果字符串没有数字和字母，防止越界 */
                    return true;
                }
            }
            
            if (isdigital(s[i])) {
                if (isletter(s[j]))
                    return false;

                if (s[i] != s[j])
                    return false;                
            } else {
                if (isdigital(s[j]))
                    return false;
                
                if (tolower(s[i]) != tolower(s[j]))
                    return false;
            }
            
            i++;
            j--;
        }

        return true;
    }
};
