

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        /* 将所有正数作为数组下标来标记数字出现与否 */
        vector<int> res;
        int i;

        /* 用负数标记出现的数字 */
        for (i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] = -1 * nums[abs(nums[i]) - 1];
        }

        /* 查找缺失的数字 */
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                res.push_back(i + 1);
        }

        return res;
    }
};
