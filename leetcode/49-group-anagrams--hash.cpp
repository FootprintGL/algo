

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> tbl;

        for (auto &str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            tbl[tmp].push_back(str);
        }

        for (auto it = tbl.begin(); it != tbl.end(); it++) {
            res.push_back(it->second);
        }

        return res;
    }
};
