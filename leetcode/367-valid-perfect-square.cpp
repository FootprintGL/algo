

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1)
            return true;

        /* 二分查找 - 范围[2, num/2] */

        /* 定义long，防止mid * mid溢出 */
        long left = 2, right = num/2, mid, mult;

        while (left <= right) {
            mid = left + (right - left) / 2;
            mult = mid * mid;
            if (mult == num)
                return true;
            else if (mult < num)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return false;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        /* int会溢出 */
        //for (int i = 1; i * i <= num; i++)
        for (long i = 1; i * i <= num; i++)
            if (i * i == num)
                return true;

        return false;
    }
};
