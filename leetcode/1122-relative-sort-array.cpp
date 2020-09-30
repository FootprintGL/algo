






class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        unordered_set<int> myset;
        map<int, int> mymap;

        /* 哈希map - 存放arr1中元素和频次 */
        for (auto c : arr1)
            mymap[c]++;

        /* 哈希set - 存放arr2中的元素 */
        for (auto c : arr2)
            myset.insert(c);

        /* 放arr2中存在的元素 */
        for (auto c : arr2) {
            for (int i = 0; i < mymap[c]; i++) {
                res.push_back(c);
            }
        }

        /* 放arr2中不存在的元素 */
        for (auto &[c, cnt] : mymap) {
            if (myset.count(c) == 0) {
                for (int i = 0; i < cnt; i++) {
                    res.push_back(c);
                }
            }
        }

        return res;
    }
};
