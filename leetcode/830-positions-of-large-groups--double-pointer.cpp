

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        /* 双指针 */
        vector<vector<int>> res;
        int n = S.length();
        int l = 0, r = 0;

        if (n < 3)
            return res;

        while (r < n) {
            r = l + 1;
            while (r < n && S[r] == S[l])
                r++;

            if (r - l >= 3)
                res.push_back({l, r - 1});

            l = r;
        }

        return res;
    }
};
