

class Solution {
public:
    bool isoletter(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }

    string toGoatLatin(string S) {
        string res, cur;
        int left = 0, right, len = S.length();
        int index = 1;

        /* 跳过开头空格
        while (left < len && S[left] == ' ') {
            left++;
            continue;
        }
        */

        right = left;
        while (right < len) {
            while (right < len && S[right] != ' ') {
                right++;
                continue;
            }

            /* 找到新单词 */
            if (isoletter(S[left])) {
                /* 元音字母 */
                res += S.substr(left, right - left);
            } else {
                /* 辅音字母 */
                res += S.substr(left + 1, right - left - 1);
                res += S[left];
            }
            res += "ma";
            for (int i = 0; i < index; i++)
                res += 'a';
            if (right != len)
                res += ' ';

            index++;
            left = right + 1;
            right = left;
        }

        return res;
    }
};
