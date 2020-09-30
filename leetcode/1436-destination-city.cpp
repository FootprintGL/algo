
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        /* 寻找出度为0的节点 */
        unordered_map<string, pair<int, int>> tbl;
        string res;

        for (auto &path : paths) {
            tbl[path[0]].second++;
            tbl[path[1]].first++;
        }

        for (auto &vertex : tbl) {
            if (vertex.second.second == 0) {
                res = vertex.first;
            }
        }

        return res;
    }
};
