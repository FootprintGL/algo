

class Solution {
public:
    bool selfdivide(int num) {
        int tmp = num;

        while (tmp) {
            int cur = tmp % 10;

            if (cur == 0 || num % cur)
                return false;

            tmp /= 10;
        }

        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;

        for (int i = left; i <= right; i++) {
            if (selfdivide(i))
                res.push_back(i);
        }

        return res;
    }
};
