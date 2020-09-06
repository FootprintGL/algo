

class Solution {
public:
    int mySqrt(int x) {
        /* long防止整数溢出 */
        long i;
        for (i = 1; i * i <= x; i++);
        return i * i == x ? i : i - 1;
    }
};
