
class Solution {
public:
    bool judgeSquareSum(int c) {
        int b = sqrt(c), a = 0;

        while (a <= b) {
            int tmp = c - a * a - b * b;
            if (tmp == 0)
                return true;
            else if (tmp < 0)
                b--;
            else
                a++;
        }

        return false;
    }
};


class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            double b = sqrt(c - a * a);
            if (b == (int)b)
                return true;
        }
        return false;
    }
};
