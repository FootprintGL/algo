

class Solution {
public:
    bool upper(char c) {
        return c <= 'Z' && c >= 'A';
    }


    bool detectCapitalUse(string word) {
        int n = word.length();
        int i;

        if (n == 1)
            return true;
        /* 分类讨论 */
        if (upper(word[0])) {
            if (upper(word[1])) {
                for (i = 2; i < n; i++)
                    if (!upper(word[i]))
                        return false;
            } else {
                for (i = 2; i < n; i++)
                    if (upper(word[i]))
                        return false;
            }
        } else {
            for (i = 1; i < n; i++)
                if (upper(word[i]))
                    return false;
        }

        return true;
    }
};
