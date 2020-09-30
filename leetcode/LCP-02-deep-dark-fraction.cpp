

class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        int denominator;
        int numerator;
        int n = cont.size();
        vector<int> res(2, 0);

        if (n == 1) {
            res[0] = cont[0];
            res[1] = 1;
            return res;
        }

        denominator = cont[n - 2] * cont[n - 1] + 1;
        numerator = cont[n - 1];
        for (int i = cont.size() - 3; i >= 0; i--) {
            int tmp = numerator;
            numerator = denominator;
            denominator = cont[i] * denominator + tmp;
        }
        res[0] = denominator;
        res[1] = numerator;

        return res;
    }
};
