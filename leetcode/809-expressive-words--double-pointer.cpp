

class Solution {
public:
    bool isstretch(string &S, string &word) {
        int i = 0, j = 0;
        int c1 = 0, c2 = 0;
        int m = S.length(), n = word.length();

        /*
         * S和word必须有相同的字母组
         * 对于每一组字母，假设S有c1个，word中有c2个
         *      1 如果c1 < c2, 那么word不能扩张到S
         *      2 如果c1 >= 3, 添加c1 - c2个字母扩张
         *      3 如果c1 < 3, 此时不能添加字母，必须有c1 == c2
         */
        while (i < m && j < n) {
            if (S[i] != word[j])
                return false;

            char c = S[i];
            c1 = c2 = 0;

            while (i < m && S[i] == c) {
                c1++;
                i++;
            }

            while (j < n && word[j] == c) {
                c2++;
                j++;
            }

            if (c1 < c2 || (c1 < 3 && c1 != c2))
                return false;
        }

        return (i != m || j != n) ? false : true;
    }

    int expressiveWords(string S, vector<string>& words) {
        int res = 0;

        /* 双指针 */
        for (auto &word : words)
            if (isstretch(S, word)) {
                //cout << word << endl;
                res++;
            }

        return res;
    }
};
