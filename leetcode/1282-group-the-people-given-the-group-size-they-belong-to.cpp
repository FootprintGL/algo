

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        /* group size相同的放在一起 */
        unordered_map<int, vector<int>> tbl;
        int n = groupSizes.size();

        /* 按group大小分组 */
        for (int i = 0; i < n; i++) {
            tbl[groupSizes[i]].push_back(i);
        }

        /* 构建结果 */
        vector<vector<int>> res;
        for (auto &t : tbl) {
            vector<int> group;
            int sz = t.first;
            for (int i = 0; i < t.second.size(); i++) {
                group.push_back(t.second[i]);
                if (group.size() == sz) {
                    /* 贪心 - 满了，开辟一个新组 */
                    res.push_back(group);
                    group.clear();
                }
            }
        }

        return res;
    }
};
