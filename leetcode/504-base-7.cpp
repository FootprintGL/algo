
class Solution {
public:
    string convertToBase7(int num) {
        string res;

        int div = 1;
        int sign = 1;

        if (num == 0)
            return "0";

        if (num < 0) {
            sign = -1;
            num = sign * num;
        }

        while (num) {
            int t = num % 7;
            num /= 7;
            res.insert(res.begin(), (char)(t + '0'));
        }

        if (sign == -1)
            res.insert(res.begin(), '-');

        return res;
    }
};
