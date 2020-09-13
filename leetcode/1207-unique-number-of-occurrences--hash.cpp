
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        /* 哈希表 */
        unordered_map<int, int> mymap;
        unordered_set<int> myset;

        for (auto &a : arr)
            mymap[a]++;

        for (auto &[num, cnt] : mymap) {
            if (myset.count(cnt))
                return false;
            myset.insert(cnt);
        }

        return true;
    }
};
