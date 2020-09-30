

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        /* 双指针 */
        int l = 0, r = 0;
        int n = nums.size();
        int ans = 0;

        while (r < n) {
            r = l + 1;
            while (r < n && nums[r] == nums[l])
                r++;

            if (nums[l] == 1)
                ans = max(ans, r - l);

            l = r;
        }

        return ans;
    }
};
