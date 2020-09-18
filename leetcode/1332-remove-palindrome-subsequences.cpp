

class Solution {
public:
    int removePalindromeSub(string s) {
        /*
         * 删除回文子序列，只有2个字母a,b, aaa...a可一次删除，bbb...b可一次删除
         * 空串0次删除，回文串一次删除
         */
        if (s.length() == 0)
            return 0;

        for (int i = 0, j = s.length() - 1; i <= j; i++, j--)
            if (s[i] != s[j])
                return 2;

        return 1;
    }
};
