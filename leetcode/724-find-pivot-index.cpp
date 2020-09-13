
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        int i, ans = -1;

        /* 前缀和 */
        for (i = 0; i < n; i++)
            sum[i + 1] = sum[i] + nums[i];

        for (i = 1; i <= n; i++) {
            if (sum[i - 1] == sum[n] - sum[i]) {
                ans = i - 1;
                break;
            }
        }

        return ans;
    }
};
