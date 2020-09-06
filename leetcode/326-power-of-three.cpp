

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0)
            return false;

        if (n == 1)
            return true;

        long i = 1;

        while (i < n) {
            i *= 3;
        }

        return (i == n);
    }
};
