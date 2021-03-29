

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        /* 双指针 - 如果相邻的1间隔不小于k，则所有的1间隔都不小于k */
        int n = nums.size();
        int l = 0;

        /* 找到第一个1 */
        while (l < n && nums[l] == 0)
            l++;

        int r = l;
        while (r < n) {
            r = l + 1;
            while (r < n && nums[r] == 0)
                r++;

            if (r == n)
                break;

            if (r - l - 1 < k)
            /* 两个1之间小于k，返回false */
                return false;

            l = r;
        }

        return true;
    }
};
