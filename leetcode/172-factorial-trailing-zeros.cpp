

class Solution {
public:
    int trailingZeroes(int n) {
        /* 10 = even * 5, 偶数一定比5多，实际上是找5的个数 */
        int cnt = 0;

        while (n) {
            cnt += n / 5;
            n /= 5;
        }

        return cnt;
    }
};
