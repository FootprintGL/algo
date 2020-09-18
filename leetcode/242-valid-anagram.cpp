
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        /* 字母异位词 - 组成字母相同，且每个字母个数也相同 */
        vector<int> let(26, 0);
        int i;

        for (i = 0; i < s.length(); i++) {
            let[s[i] - 'a']++;
            let[t[i] - 'a']--;
        }
        
        for (auto cnt : let)
            if (cnt != 0)
                return false;
        
        return true;
    }
};


class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> tbl;

        if (s.length() != t.length())
            return false;

        /* 字母异位词 - 组成字母相同，且每个字母个数也相同 */
        for (auto c : s)
            tbl[c]++;

        for (auto c : t)
            tbl[c]--;

        for (auto &[c, cnt] : tbl)
            if (cnt != 0)
                return false;

        return true;
    }
};
