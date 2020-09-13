
class Solution {
public:
    int power(int base, int exp) {
        if (exp == 0)
            return 1;
        int ret = 1;
        while (exp > 0) {
            ret *= base;
            exp--;
        }
        return ret;
    }

    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> res;
        unordered_set<int> myset;
        int i, j;

        /* 1 ^ i为1，如果x,y为1，跳出相应循环即可 */
        for (i = 0; power(x, i) < bound; i++) {
            for (j = 0; power(x, i) + power(y, j) <= bound; j++) {
                myset.insert(power(x, i) + power(y, j));
                if (y == 1)
                    break;
            }
            if (x == 1)
                break;
        }

        for (auto a : myset)
            res.push_back(a);

        return res;
    }
};

class Solution {
public:
    int power(int base, int exp) {
        if (exp == 0)
            return 1;
        int ret = 1;
        while (exp > 0) {
            ret *= base;
            exp--;
        }
        return ret;
    }

    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> res;
        unordered_set<int> myset;
        int i, j;

        /* x,y为正整数， x ^ i + y ^ i >= 2 */
        if (bound < 2)
            return {};

        /* 1 ^ i 等于1，需要特殊考虑 */
        if (x == 1 && y == 1 && bound >= 2)
            return {2};

        if (x == 1)
        /* 如果有一个数为1，转换让第二个数y为1 */
            return powerfulIntegers(y, x, bound);

        if (y == 1) {
            for (i = 0; power(x, i) < bound; i++) {
                myset.insert(power(x, i) + 1);
            }
        } else {
            for (i = 0; power(x, i) < bound; i++) {
                for (j = 0; power(y, j) < bound; j++) {
                    if (power(x, i) + power(y, j) <= bound)
                        myset.insert(power(x, i) + power(y, j));
                }
            }
        }

        for (auto a : myset)
            res.push_back(a);

        return res;
    }
};
