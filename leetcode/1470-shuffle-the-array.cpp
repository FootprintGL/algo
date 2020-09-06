

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n, 0);
        int i = 0, j = n, k = 0;

        /* 交替依次放入 */
        while (k < 2 * n) {
            ans[k++] = nums[i++];
            ans[k++] = nums[j++];
        }

        return ans;
    }
};
