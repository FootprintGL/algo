

class Solution {
public:
    string reorderSpaces(string text) {
        string res;
        vector<string> words;
        int cnt = 0, n = text.size();
        int i = 0, j = 0;

        /* 单词拆分, 空格统计 */
        while (j < n) {
            while (i < n && text[i] == ' ') {
                i++;
                cnt++;
            }

            if (i == n)
                break;

            j = i + 1;
            while (j < n && text[j] != ' ')
                j++;
            words.push_back(text.substr(i, j - i));
            i = j;
        }
        //cout << words.size() << " " << cnt << endl;

        int div, rem;
        if (words.size() == 1) {
            div = 0;
            rem = cnt;
        } else {
            div = cnt / (words.size() - 1);
            rem = cnt % (words.size() - 1);
        }

        /* 每个单词中间插入平均的空格 */
        for (i = 0; i < words.size() - 1; i++) {
            res += words[i];
            for (j = 0; j < div; j++)
                res += ' ';
        }
        /* 放最后一个单词和剩下的空格 */
        res += words[words.size() - 1];
        for (j = 0; j < rem; j++)
            res += ' ';

        return res;
    }
};
