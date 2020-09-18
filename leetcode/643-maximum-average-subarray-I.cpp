
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = nums[0];
        int n = nums.size(), i;

        /* 前缀和 */
        for (i = 1; i < n; i++)
            nums[i] += nums[i - 1];

        res = 1.0 * nums[k - 1] / k;
        for (i = k; i < n; i++) {
            res = max(res, 1.0 * (nums[i] - nums[i - k]) / k);
        }

        return res;
    }
};
