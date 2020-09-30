

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /* 异或 - 相同的数异或为0 */
        int n = nums.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            res ^= i ^ nums[i];
        }

        return res ^ n;
    }
};
