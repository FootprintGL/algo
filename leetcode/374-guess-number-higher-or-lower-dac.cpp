/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    /* 二分法 */
    int helper(int left, int right) {
        if (left == right)
            return left;

        int mid = left + (right - left) / 2;
        if (guess(mid) == -1)
            return helper(left, mid - 1);
        else if (guess(mid) == 1)
            return helper(mid + 1, right);
        else
            return mid;
    }

    int guessNumber(int n) {
        return helper(1, n);
    }
};
