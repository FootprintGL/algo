class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> myset;
        vector<int> res;

        /* 哈希表 */
        if (nums1.size() < nums2.size()) {
            for (auto x : nums1)
                myset.insert(x);
            for (auto x : nums2)
                if (myset.count(x)) {
                    res.push_back(x);
                    myset.erase(x);
                }
        } else {
            for (auto x : nums2)
                myset.insert(x);
            for (auto x : nums1)
                if (myset.count(x)) {
                    res.push_back(x);
                    myset.erase(x);
                }
        }

        return res;
    }
};
