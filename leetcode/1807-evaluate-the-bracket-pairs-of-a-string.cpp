

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> tbl;
        bool iskey = false;
        string key;
        string res;

        /* 哈希表加速查找 */
        for (int i = 0; i < knowledge.size(); i++)
            tbl[knowledge[i][0]] = knowledge[i][1];

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                /* key开始 */
                iskey = true;
            } else if (s[i] == ')') {
                /* key结束 */
                iskey = false;
                if (tbl.count(key))
                    res += tbl[key];
                else
                    res += '?';
                key.clear();
            } else {
                if (iskey)
                    key += s[i];
                else
                    res += s[i];
            }
        }

        return res;
    }
};
