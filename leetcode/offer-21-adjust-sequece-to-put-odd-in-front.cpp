

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        /* 双指针 */
        int n = nums.size();
        if (n == 1)
            return nums;

        int l = 0, r = n - 1;

        while (l <= r) {
            while (l < r && nums[l] % 2)
                l++;
            while (l < r && nums[r] % 2 == 0)
                r--;

            int tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
            l++;
            r--;
        }

        return nums;
    }
};
