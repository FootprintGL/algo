

class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        /* 排序 + 逐渐逼近 */
        int m = a.size(), n = b.size();
        int i = 0, j = 0;
        long res = INT_MAX;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        while (i < m && j < n) {
            res = min(res, abs((long)a[i] - (long)b[j]));

            if (res == 0)
                break;

            if (a[i] < b[j])
            /* a尽可能逼近b */
                i++;
            else
            /* b尽可能逼近a */
                j++;
        }

        return res;
    }
};
