class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size(), minsum;

        /* 找前缀和的最小值 */
        minsum = nums[0];
        for (int i = 1; i < n; i++) {
            nums[i] = nums[i - 1] + nums[i];
            if (nums[i] < minsum)
                minsum = nums[i];
        }

        return minsum >= 0 ? 1 : 1 - minsum;
    }
};

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size(), minsum;
        vector<int> sum(n, 0);

        /* 找前缀和的最小值 */
        minsum = sum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + nums[i];
            if (sum[i] < minsum)
                minsum = sum[i];
        }

        return minsum >= 0 ? 1 : 1 - minsum;
    }
};
