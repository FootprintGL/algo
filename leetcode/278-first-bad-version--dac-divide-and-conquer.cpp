// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    /* 二分法 */
    int helper(int left, int right) {
        if (left >= right) {
            if (isBadVersion(left) == false)
                return left + 1;
            else
                return left;
        }

        int mid = left + (right - left) / 2;
        if (isBadVersion(mid) == true)
            return helper(left, mid - 1);
        else
            return helper(mid + 1, right);
    }

    int firstBadVersion(int n) {
       return helper(1, n);
    }
};
