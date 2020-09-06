

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int start, end;

        /* 去掉末尾的空格 */
        end = len - 1;
        while (end >= 0 && s[end] == ' ')
            end--;

        /* 找出最后一个单词前面的空格 */
        start = end;
        while (start >= 0 && s[start] != ' ')
            start--;

        return end - start;
    }
};
