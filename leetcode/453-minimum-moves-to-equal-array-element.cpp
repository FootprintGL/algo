

class Solution {
public:
    int minMoves(vector<int>& nums) {
        /* 脑筋急转弯 - n - 1数都加一，相当与一个数减1，结果为所有值与最小值差值和 */
        int res = 0;
        int minvalue = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < minvalue)
                minvalue = nums[i];
        }

        for (auto &num : nums)
            res += num - minvalue;

        return res;
    }
};
