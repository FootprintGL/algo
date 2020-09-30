

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        /* 最大是次大的2倍 */
        int fmax = -1, smax = -1;
        int n = nums.size(), ans = 0;

        if (n == 1)
            return 0;

        fmax = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= fmax) {
                smax = fmax;
                fmax = nums[i];
                ans = i;
            } else if (nums[i] < fmax && nums[i] > smax) {
                smax = nums[i];
            }
        }

        //cout << fmax << " " << smax << endl;

        return fmax >= smax * 2 ? ans : -1;
    }
};
