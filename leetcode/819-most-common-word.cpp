

class Solution {
public:
    bool letter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    string lower(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 'a' - 'A';
        }
        return s;
    }

    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban;
        unordered_map<string, int> mymap;

        for (auto &word : banned)
            ban.insert(word);

        int l = 0, r = 0;
        int len = paragraph.length();
        int maxcnt = 0;
        string ans;

        while (l < len) {
            while (l < len && !letter(paragraph[l]))
            /* 跳过单词开头的非字母符号 */
                l++;

            if (l == len)
                break;

            r = l + 1;
            while (r < len && letter(paragraph[r]))
                r++;

            //cout << l << " " << r << endl;
            /* 找到单词右边的分隔符，r -> r - 1构成一个单词，统计入map */
            mymap[lower(paragraph.substr(l, r - l))]++;

            l = r + 1;
        }

        /* 查找出现次数最多的单词 */
        for (auto &[word, cnt] : mymap) {
            if (ban.find(word) != ban.end())
            /* 跳过ban里的单词 */
                continue;
            if (cnt > maxcnt) {
                maxcnt = cnt;
                ans = word;
            }
        }

        return ans;
    }
};
