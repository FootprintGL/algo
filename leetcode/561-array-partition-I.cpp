
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        /* 数组排序，相邻元素组合为最大, 结果为排序后奇数位置元素和 */
        int ans = 0;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i = i + 2) {
            ans += nums[i];
        }

        return ans;
    }
};
