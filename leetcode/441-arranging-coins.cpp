

class Solution {
public:
    int arrangeCoins(int n) {
        /* 二分法 */
        int left = 1, right = n;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long tmp = mid * (mid + 1) / 2;
            if (tmp < n) {
                left = mid + 1;
            } else if (tmp > n) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return right;
    }
};


class Solution {
public:
    int arrangeCoins(int n) {
        long i;
        for (i = 1; i * (i + 1) / 2 <= n; i++);
        return i - 1;
    }
};
