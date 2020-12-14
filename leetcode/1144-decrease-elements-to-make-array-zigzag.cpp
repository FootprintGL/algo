

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        /* 分开考虑2中类型，去操作次数较小的 */
        int n = nums.size();
        int ecnt = 0, ocnt = 0;

        /* 偶数索引大于相邻元素 */
        for (int i = 1; i < n; i += 2) {
            if (i != n - 1) {
                ecnt += max(0, nums[i] - min(nums[i - 1], nums[i + 1]) + 1);
            } else {
                ecnt += max(0, nums[i] - nums[i - 1] + 1);
            }
        }

        /* 奇数索引大于相邻元素 */
        for (int i = 0; i < n; i += 2) {
            if (i == 0) {
                ocnt += max(0, nums[i] - nums[i + 1] + 1);
            } else if (i == n - 1) {
                ocnt += max(0, nums[i] - nums[i - 1] + 1);
            } else {
                ocnt += max(0, nums[i] - min(nums[i - 1], nums[i + 1]) + 1);
            }
        }

        //cout << ecnt << " " << ocnt << endl;

        return min(ecnt, ocnt);
    }
};
