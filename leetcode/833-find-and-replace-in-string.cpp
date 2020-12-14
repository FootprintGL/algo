

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string res;
        int n = S.length(), i, j;
        unordered_map<int, int> tbl;

        /* 哈希表加速查找 */
        for (i = 0; i < indexes.size(); i++)
            tbl[indexes[i]] = i;

        for (i = 0; i < n; i++) {
            if (tbl.find(i) == tbl.end()) {
                /* 不再index中 */
                res += S[i];
                continue;
            } else {
                int len = sources[tbl[i]].length();
                if (S.substr(i, len) == sources[tbl[i]]) {
                    /* 匹配成功 */
                    res += targets[tbl[i]];
                    i += len - 1;
                } else {
                    /* 匹配失败 */
                    res += S[i];
                    continue;
                }
            }
        }

        return res;
    }
};
