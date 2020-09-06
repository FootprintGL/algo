

class Solution {
public:
    bool helper(string s, string t) {
        unordered_map<char, char> dic;

        for (int i = 0; i < s.length(); i++) {
            if (dic.count(s[i])) {
                if (dic[s[i]] != t[i])
                    return false;
            } else {
                dic[s[i]] = t[i];
            }
        }

        return true;
    }

    bool isIsomorphic(string s, string t) {
        /*
         * 哈希表保存字母到字母的映射关系，如果一个字母映射到不同字母，
         * 则不是同构字符串, 需要s->t, t->s分别检查
         */
        return helper(s, t) && helper(t, s);
    }
};
