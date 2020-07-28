



class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int left, right, mid;
        int cnt = 0;
        long long sum = 0;
        int i;

        /*
         * 二分查找
         * 子数组和的最大值范围为[max(nums[i]) - n组,  -- sum(nums[i]) - 1组], i: 0 -> n - 1
         * 猜一个中间的数对nums进行分组，如果分组数大于n，则结果在[mid+1, right]
         * 如果分组数小于n，则结果在(left, mid)
         */
        /* 计算子数组和最大值范围 */
        sum = left = nums[0];
        for (i = 1; i < n; i++) {
            sum += nums[i];
            if (nums[i] > left)
                left = nums[i];
        }
        right = sum;

        while (left < right) {
            mid = left + (right - left) / 2;
            cnt = 1;
            sum = 0;
            /* 以mid为基准分组，统计分组数 */
            for (i = 0; i < n; i++) {
                if (sum + nums[i] > mid) {
                    cnt++;
                    sum = nums[i];
                } else {
                    sum += nums[i];
                }
            }
            if (cnt <= m)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};




class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        /*
         * int型会出错
         * 测试用例
         * [1,2147483647]
         * 2
        */
        vector<vector<long long>> dp(n + 1, vector<long long> (m + 1, LLONG_MAX));
        vector<long long> sums (n + 1, 0);
        int sum = 0, submax;
        int i, j, k;

        /* 前缀和 */
        for (i = 0; i < n; i++)
            sums[i + 1] = sums[i] + nums[i];

        /*
         * 动态规划
         * dp[i][j] - 前i个元素分成j段各连续子数组和的最小值
         * 假设前k个分成j - 1组, 则有转移方程，dp[i][j] = min(max(dp[k][j - 1]], sums[i] - sums[k]) k: 0 -> i - 1 - 1
         * 逐行进行计算，i < j时无法分组, j的取值范围为1~min(i,m)
         */
        dp[0][0] = 0;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= min(i, m); j++) {
                for (k = 0; k < i; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sums[i] - sums[k]));
                }
            }
        }

        return (int)dp[n][m];
    }
};
