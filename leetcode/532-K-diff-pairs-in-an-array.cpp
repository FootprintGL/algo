

class Solution {
public:
    struct pair_hash {
        template<class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2>& p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1^h2;
        }
    };

    int findPairs(vector<int>& nums, int k) {
        /* 哈希表 */
        int res = 0;
        unordered_map<int, int> tbl;
        unordered_set<pair<int, int>, pair_hash> myset;

        /* 绝对值必然大于等于0 */
        if (k < 0)
            return 0;

        for (auto &num : nums)
            tbl[num]++;

        if (k != 0) {
            /* 找num - k */
            for (auto &[num, cnt] : tbl) {
                if (tbl.count(num - k))
                    myset.insert({num - k, num});
            }
            res = myset.size();
        } else {
            /* 找相等元素 */
            for (auto &[num, cnt] : tbl)
                if (cnt >= 2)
                    res++;
        }

        return res;
    }
};
