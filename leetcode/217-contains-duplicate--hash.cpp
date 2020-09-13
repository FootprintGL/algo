
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /* 哈希表 */
        unordered_set<int> tbl;

        for (auto num : nums) {
            if (tbl.count(num))
                return true;
            else
                tbl.insert(num);
        }

        return false;
    }
};
