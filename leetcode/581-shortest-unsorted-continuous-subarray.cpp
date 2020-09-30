

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy(nums);
        int l = 0, r = nums.size() - 1;

        /* 排序 - 从两边统计已经归位元素 */
        sort(copy.begin(), copy.end());

        while (l <= r && nums[l] == copy[l])
            l++;

        while (r >= l && nums[r] == copy[r])
            r--;

        return r - l + 1;
    }
};
