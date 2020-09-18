

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        vector<string> tmp;

        int l = 0;
        int r = 0;
        int n = text.length();

        /* 单词放入数组tmp */
        while (r < n) {
            r = l + 1;
            while (r < n && text[r] != ' ')
                r++;
            tmp.push_back(text.substr(l, r - l));
            l = r + 1;
        }

        /* 匹配first + second */
        for (int i = 0; i < tmp.size() - 2; i++) {
            if (tmp[i] + tmp[i + 1] == first + second)
                res.push_back(tmp[i + 2]);
        }

        return res;
    }
};
