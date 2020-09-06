
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        /* 前i个数字构成x，则前i + 1个数字构成2 * x + A[i] */
        int n = A.size();
        vector<bool> ans(n, false);
        int x = 0, i;

        for (i = 0; i < n; i++) {
            /* 只需要保留5的余数，避免溢出 */
            x = (x * 2 + A[i]) % 5;
            if (x == 0)
                ans[i] = true;
        }

        return ans;
    }
};


class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        /* 前i个数字构成x，则前i + 1个数字构成2 * x + A[i] */
        int n = A.size();
        vector<bool> ans(n, false);
        int x = 0, i;

        for (i = 0; i < n; i++) {
            /* 只需要保留个位，避免溢出 */
            x = (x * 2 + A[i]) % 10;
            if (x == 0 || x == 5)
                ans[i] = true;
        }

        return ans;
    }
};
