

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> tbl;
        int ans = 0;

        /* 哈希表 */
        for (auto &a : J)
            tbl.insert(a);

        for (auto &a : S)
            if (tbl.count(a))
                ans++;

        return ans;
    }
};
