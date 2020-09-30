
class Solution {
public:
    int maximum69Number (int num) {
        /* 从左往右地一个6变成9 */
        int factor = 1;
        int lfactor = -1;
        int tmp = num;

        while (num) {
            int cur = num % 10;
            if (cur == 6) {
                lfactor = factor;
            }
            factor *= 10;
            num /= 10;
        }

        return lfactor == -1 ? tmp : tmp + 3 * lfactor;
    }
};
