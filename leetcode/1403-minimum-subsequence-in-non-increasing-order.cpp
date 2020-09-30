

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> res;
        int sum = 0, target;

        /* 找最大元素子序列大于数组元素和的一半 */
        sort(nums.begin(), nums.end(), ::greater());
        for (auto num : nums)
            sum += num;

        target = sum / 2;
        sum = 0;
        for (auto num : nums) {
            res.push_back(num);
            sum += num;
            if (sum > target)
                break;
        }

        return res;
    }
};
