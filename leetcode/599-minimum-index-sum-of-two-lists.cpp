

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        /* 哈希表 */
        vector<string> res;
        unordered_map<string, int> tbl1;
        int i, index = 2000;

        for (i = 0; i < list1.size(); i++)
            tbl1[list1[i]] = i;

        for (i = 0; i < list2.size(); i++) {
            if (tbl1.count(list2[i])) {
                if (i + tbl1[list2[i]] == index) {
                    res.push_back(list2[i]);
                } else if (i + tbl1[list2[i]] < index) {
                    index = i + tbl1[list2[i]];
                    res.clear();
                    res.push_back(list2[i]);
                }
            }
        }

        return res;
    }
};
