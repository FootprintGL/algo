

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        /* 哈希表 */
        unordered_set<int> myset;

        for (auto c : candies)
            myset.insert(c);

        return min(candies.size() / 2, myset.size());
    }
};
