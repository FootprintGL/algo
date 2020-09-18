

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.length(), i, prev;
        vector<int> res(n, 0);

        /* 分别计算每个字母到左边C的距离和右边C的距离，取最小值 */

        /* 左边没有C是距离为无穷大 */
        prev = -20000;
        for (i = 0; i < n; i++) {
            if (S[i] == C) {
                prev = i;
            } else {
                res[i] = i - prev;
            }
        }

        /* 右边没有C是距离为无穷大 */
        prev = 20000;
        for (i = n - 1; i >= 0; i--) {
            if (S[i] == C) {
                prev = i;
            } else {
                res[i] = min(res[i], prev - i);
            }
        }

        return res;
    }
};
