

class Solution {
public:
    int helper(string s) {
        int let[26] = {0};
        int res, i;

        for (auto &c : s)
            let[c - 'a']++;

        for (i = 0; i < 26; i++)
            if (let[i] != 0)
                return let[i];

        return -1;
    }

    int bicount(int target, vector<int> &wf) {
        int res = 0;
        int l = 0, r = wf.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (target >= wf[m]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return l == wf.size() ? 0 : wf.size() - l;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int m = queries.size();
        int n = words.size(), i;

        vector<int> res(m, 0);
        vector<int> wf(n, 0);

        /* 计算f(words) */
        for (i = 0; i < n; i++) {
            wf[i] = helper(words[i]);
        }
        sort(wf.begin(), wf.end());

        /* 计算并统计结果 */
        for (i = 0; i < m; i++) {
            res[i] = bicount(helper(queries[i]), wf);
        }

        return res;
    }
};
