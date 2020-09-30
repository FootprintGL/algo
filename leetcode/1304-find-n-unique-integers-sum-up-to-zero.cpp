

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res (n, 0);

        for (int i = 0; i < n / 2; i++) {
            res[i] = i + 1;
            res[n - i - 1] = -1 * (i + 1);
        }

        return res;
    }
};
