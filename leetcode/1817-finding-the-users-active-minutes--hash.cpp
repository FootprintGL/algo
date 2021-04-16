

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        /* 哈希表 */
        vector<int> res(k, 0);
        unordered_map<int, unordered_set<int>> tbl;
        int n = logs.size();

        for (int i = 0; i < n; i++) {
            tbl[logs[i][0]].insert(logs[i][1]);
        }

        for (auto &cnt : tbl) {
            res[cnt.second.size() - 1]++;
        }

        return res;
    }
};
