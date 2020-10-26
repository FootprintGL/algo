
class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /* 哈希表 */
        vector<vector<string>> res;
        /* 如果构建key - 可以对元素进行排序作为k， */
        unordered_map<string, vector<string>> tbl;
        int n = strs.size();
        int i, j;

        /* 搜索变位词并放入哈希表 */
        for (auto &s : strs) { 
            string key = s;
            sort(key.begin(), key.end());
            tbl[key].push_back(s);
        }

        /* 构建结果 */
        for (auto &t : tbl) {
            res.push_back(t.second);
        }
        
        return res;
    }
};



/* 超时 */
class Solution {
public:
    /* 检测变位词 */
    bool difpos(string w1, string w2) {
        //cout << w1 << " " << w2 << " " << (w1 == w2) << endl;
        sort(w1.begin(), w1.end());
        sort(w2.begin(), w2.end());
        return w1 == w2;
    }

    bool dispos2(string &w1, string &w2) {
        if (w1.length() != w2.length())
            return false;
        unordered_map<char, int> tbl;
        for (auto &c: w1) {
            tbl[c]++;
        }
        for (auto &c: w2) {
            if (tbl.count(c) == 0)
                return false;
            tbl[c]--;
        }

        for (auto &t: tbl)
            if (t.second)
                return false;
        
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /* 哈希表 */
        vector<vector<string>> res;
        unordered_map<string, vector<string>> tbl;
        int n = strs.size();
        vector<bool> visited(n, false);
        int i, j;

        /* 搜索变位词并放入哈希表 */
        for (i = 0; i < n; i++) { 
            if (visited[i])
                continue;
            visited[i] = true;
            for (j = i; j < n; j++) {
                if (dispos2(strs[i], strs[j])) {
                    /* 变位词放入哈希表 */
                    tbl[strs[i]].push_back(strs[j]);
                    visited[j] = true;
                }
            }
        }

        /* 构建结果 */
        for (auto &t : tbl) {
            vector<string> tmp;
            for (auto t1 : t.second)
                tmp.push_back(t1);
            res.push_back(tmp);
        }
        
        return res;
    }
};



/* 超时 */
class Solution {
public:
    /* 检测变位词 */
    bool difpos(string w1, string w2) {
        //cout << w1 << " " << w2 << " " << (w1 == w2) << endl;
        sort(w1.begin(), w1.end());
        sort(w2.begin(), w2.end());
        return w1 == w2;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /* 哈希表 */
        vector<vector<string>> res;
        unordered_map<string, vector<string>> tbl;
        int n = strs.size();
        vector<bool> visited(n, false);
        int i, j;

        /* 搜索变位词并放入哈希表 */
        for (i = 0; i < n; i++) {
            if (visited[i])
                continue;
            visited[i] = true;
            for (j = i; j < n; j++) {
                if (difpos(strs[i], strs[j])) {
                    /* 变位词放入哈希表 */
                    tbl[strs[i]].push_back(strs[j]);
                    visited[j] = true;
                }
            }
        }

        /* 构建结果 */
        for (auto &t : tbl) {
            vector<string> tmp;
            for (auto t1 : t.second)
                tmp.push_back(t1);
            res.push_back(tmp);
        }

        return res;
    }
};
