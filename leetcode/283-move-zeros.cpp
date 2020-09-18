

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /* 双指针 */
        int l = 0, r = 0;
        int n = nums.size();

        /* 把非0元素移到数组前面 */
        while (r < n) {
            while (r < n && nums[r] == 0)
                r++;

            if (r == n)
                break;

            nums[l++] = nums[r++];
        }

        /* 剩下元素补0 */
        while (l < n)
            nums[l++] = 0;
    }
};
