

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> tbl1;
        unordered_map<string, char> tbl2;
        /* stringstream分离单词 */
        stringstream ss(s);
        string tmp;
        for (int i = 0; i < pattern.length(); i++) {
            ss >> tmp;
            //cout << pattern[i] << " " << tmp << endl;
            if (tmp == "" || (tbl1.count(pattern[i]) && tbl1[pattern[i]] != tmp) || (tbl2.count(tmp) && tbl2[tmp] != pattern[i]))
                return false;
            tbl1[pattern[i]] = tmp;
            tbl2[tmp] = pattern[i];
        }

        return (ss >> tmp) ? false : true;
    }
};
