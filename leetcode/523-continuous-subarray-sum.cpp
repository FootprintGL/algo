
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        if (n < 2)
            return false;

        /* 
         * 同余定理sum[i] - sum[i] = k * x -> sum[i] % k == sum[j] % k
         * k != 0 计算前缀和，保存sum % k
         * k == 0, 保存sum
         */
        unordered_map<int, int> map;
        int sum = 0, i;
        /* 
         * 第一次遇到前缀和为0时返回true，无论k是否等于0都成立
         * 如果前缀和为0，从开始到当前前缀结尾的所有数字都为0，0 * k -> 0, 
         * 只要不是第一个数字，就可以返回true
         */
        map[0] = -1;
        for (i = 0; i < n; i++) {
            sum += nums[i];
            if (k != 0)
                sum %= k;
            if (map.count(sum) != 0) {
                if (i - map[sum] > 1) {
                    return true;
                }
            } else {
                map[sum] = i;
            }
        }

        return false;
    }
};


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2)
            return false;

        /* 前缀和 */
        vector<int> sums(n + 1, 0);
        int i, j;
        for (i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        for (i = 1; i < n; i++) {
            for (j = i + 1; j <= n; j++) {
                if (k == 0) {
                    if ((sums[j] - sums[i - 1]) == 0)
                        return true;
                } else {
                    /* 判断子数组能否被k整除 */
                    if ((sums[j] - sums[i - 1]) % k == 0)
                        return true;
                }
            }
        }

        return false;
    }
};
