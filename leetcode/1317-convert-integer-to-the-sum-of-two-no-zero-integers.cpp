
class Solution {
public:
    bool containzero(int n) {
        while (n) {
            int cur = n % 10;
            if (cur == 0)
                return true;
            n /= 10;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        vector<int> res(2, 0);

        for (int i = 1; i <= n / 2; i++) {
            if (!containzero(i) && !containzero(n - i)) {
                res[0] = i;
                res[1] = n - i;
                break;
            }
        }

        return res;
    }
};
