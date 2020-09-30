
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        unordered_map<char, int> tbl;
        int m = s1.length();
        int n = s2.length();

        /* 哈希表 */
        for (auto &c : s1)
            tbl[c]++;

        for (auto &c : s2) {
            if (!tbl.count(c))
                return false;
            else
                tbl[c]--;
        }

        for (auto &[c, cnt] : tbl)
            if (cnt != 0)
                return false;

        return true;
    }
};
