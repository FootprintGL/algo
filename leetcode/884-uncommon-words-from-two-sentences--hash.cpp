

class Solution {
public:
    /* 单词分割 */
    void helper(unordered_map<string, int> &tbl, string s) {
        int len = s.length();
        int left, right;

        if (len == 0)
            return ;

        left = right = 0;
        while (right < len) {
            while (right < len && s[right] != ' ') {
                right++;
                continue;
            }
            tbl[s.substr(left, right - left)]++;
            left = right + 1;
            right = left;
        }
    }

    vector<string> uncommonFromSentences(string A, string B) {
        /* 哈希表 */
        unordered_map<string, int> tbl;
        vector<string> res;

        /* A,B单词全部放入tbl */
        helper(tbl, A);
        helper(tbl, B);

        /* 只出现一次则为不常见单词 */
        for (auto [s, cnt] : tbl) {
            //cout << s << " " << cnt << endl;
            if (cnt == 1)
                res.push_back(s);
        }

        return res;
    }
};
