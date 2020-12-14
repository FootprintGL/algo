




/* 暴力算法 - 超时 */
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int i, j, k;
        int n = nums.size(), res = 0;

        /* 暴力 */
        sort(nums.begin(), nums.end());

        for (i = 0; i < n - 2; i++) {
            for (j = i + 1; j < n - 1; j++) {
                for (k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] > nums[k])
                    /* 两条短边之和大于长边可构成三角形 */
                        res++;
                }
            }
        }

        return res;
    }
};
