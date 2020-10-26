

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int res = -1, idx1 = -1, idx2 = -1;

        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                idx1 = i;
            } else if (words[i] == word2) {
                idx2 = i;
            } else {
                continue;
            }

            //cout << idx1 << " " << idx2 << endl;
            if (idx1 == -1 || idx2 == -1)
                continue;

            if (abs(idx1 - idx2) < res || res == -1)
                res = abs(idx1 - idx2);
            //cout << idx1 << " " << idx2 << " " << res << endl;
        }

        return res;
    }
};




class Solution {
public:
    unordered_map<string, vector<int>> tbl;

    /* 搜索最短距离 */
    int findshortestdis(vector<int> &idx1, vector<int> &idx2) {
        int res = INT_MAX;
        int i = 0, j = 0;

        for (i = 0; i < idx1.size(); i++) {
            for (j = 0; j < idx2.size(); j++) {
                if (res > abs(idx1[i] - idx2[j])) {
                    res = abs(idx1[i] - idx2[j]);
                }
            }
        }

        return res;
    }

    int findClosest(vector<string>& words, string word1, string word2) {
        /* tbl1/tbl2存放word1/word2在词典中的位置坐标 */
        for (int i = 0; i < words.size(); i++) {
            tbl[words[i]].push_back(i);
        }

        return findshortestdis(tbl[word1], tbl[word2]);
    }
};

class Solution {
public:
    /* 搜索最短距离 */
    int findshortestdis(vector<int> &idx1, vector<int> &idx2) {
        int res = INT_MAX;
        int i = 0, j = 0;

        for (i = 0; i < idx1.size(); i++) {
            for (j = 0; j < idx2.size(); j++) {
                if (res > abs(idx1[i] - idx2[j])) {
                    res = abs(idx1[i] - idx2[j]);
                }
            }
        }

        return res;
    }

    int findClosest(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int>> tbl;
        int i, j, res;

        /* tbl1/tbl2存放word1/word2在词典中的位置坐标 */
        for (i = 0; i < words.size(); i++) {
            if (words[i] == word1)
                tbl[word1].push_back(i);
            else if (words[i] == word2)
                tbl[word2].push_back(i);
        }

        return findshortestdis(tbl[word1], tbl[word2]);
    }
};
