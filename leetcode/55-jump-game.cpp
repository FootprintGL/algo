

class Solution {
public:
    bool canJump(vector<int>& nums) {
        /* 遍历更新最多向右能到达的位置，看能否达到最后一个 */
        int n = nums.size();
        int vmax = 0;

        for (int i = 0; i < n; i++) {
            if (i <= vmax) {
                vmax = max(vmax, i + nums[i]);
                if (vmax >= n - 1)
                    return true;
            } else {
                break;
            }
        }

        return false;
    }
};
