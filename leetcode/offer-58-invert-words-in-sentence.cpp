
class Solution {
public:
    string reverseWords(string s) {
        string res;
        int left, right;
        int len = s.size();

        if (len == 0)
            return res;

        left = right = 0;

        while (right < len) {
            while (left < len && s[left] == ' ') {
                left++;
            }
            /* 末尾全是空格 */
            if (left == len)
                break;

            right = left + 1;
            while (right < len && s[right] != ' ')
                right++;

            /* 找到新单词，[left, right)左闭右开 */
            res.insert(0, s.substr(left, right - left));
            res.insert(res.begin(), ' ');
            left = right + 1;
        }

        /* 删除多加入的空格 */
        if (res.size())
            res.erase(res.begin());

        return res;
    }
};
