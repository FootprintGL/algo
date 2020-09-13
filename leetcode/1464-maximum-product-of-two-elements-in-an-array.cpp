

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /* 数组元素为正整数，题目实际是求数组的最大值和次大值 */
        int max1st, max2nd;

        max1st = max(nums[0], nums[1]);
        max2nd = min(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] >= max1st) {
                max2nd = max1st;
                max1st = nums[i];
            } else if (nums[i] < max1st && nums[i] > max2nd) {
                max2nd = nums[i];
            }
        }

        return (max1st - 1) * (max2nd - 1);
    }
};
