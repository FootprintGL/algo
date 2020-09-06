

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int n = A.size();
        vector<unordered_map<char, int>> maptbl (n);
        vector<string> ans;
        string s;

        /* 哈希表map统计没个单词各个字母出现的次数，从而找出公共的字符序列 */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < A[i].length(); j++) {
                maptbl[i][A[i][j]]++;
            }
        }

        for (int i = 0; i < 26; i++) {
            int cnt = INT_MAX;
            for (int j = 0; j < n; j++) {
                cnt = min(cnt, maptbl[j]['a' + i]);
            }
            for (int k = 0; k < cnt; k++) {
                s.clear();
                s.push_back('a' + i);
                ans.push_back(s);
            }
        }

        return ans;
    }
};
