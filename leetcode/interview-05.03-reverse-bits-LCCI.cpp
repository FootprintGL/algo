

class Solution {
public:
    /* 0分割并记录0左边和右边连续1的个数 */
    int reverseBits(int num) {
        int ans = 0;
        int pre = 0, cur = 0, cnt = 0;

        if (num == -1)
            return 32;

        while (num && cnt < 32) {
            if (num & 1) {
                cur++;
            } else {
                pre = cur;
                cur = 0;
            }

            num >>= 1;
            ans = max(ans, cur + pre);
            cnt++;
        }

        return ans + 1;
    }
};
