
class Solution {
public:
    /* 判断s2是否为s1的前缀 */
    bool ispre(string s1, string s2) {
        //cout << s1 << " " << s2 << endl;
        return s1.substr(0, s2.length()) == s2;
    }

    int isPrefixOfWord(string sentence, string searchWord) {
        int l, r;
        int n = sentence.length();
        int m = searchWord.length();
        int index = 0;

        l = r = 0;
        while (r < n) {
            r = l;
            while (r < n && sentence[r] != ' ')
                r++;
            /* 找到单词[l, r) */
            index++;
            //cout << l << " " << r << endl;
            if (r - l >= m && ispre(sentence.substr(l, r - l), searchWord)) {
                return index;
            }
            l = r + 1;
        }

        return -1;
    }
};
