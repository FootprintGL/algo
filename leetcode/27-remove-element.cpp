

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /* 双指针 */
        int l = 0, r = 0;

        for (r = 0; r < nums.size(); r++) {
            if (nums[r] == val)
                continue;
            nums[l++] = nums[r];
        }

        return l;
    }
};
