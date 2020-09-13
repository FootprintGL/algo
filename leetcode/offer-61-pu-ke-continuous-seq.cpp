class Solution {
public:
    bool isStraight(vector<int>& nums) {
        /*
         * 顺子条件
         * 除大小王外没有重复元素
         * 最大的牌为imax,最小的牌为imin imax - imin < 5
         */
        int imax, imin;
        int i = 0;

        /* 对牌排序 */
        sort(nums.begin(), nums.end());
        
        /* 最大牌 */
        imax = nums[4];

        /* 跳过大小王 */
        while (i < 5 && nums[i] == 0)
            i++;

        /* 最小牌 */
        imin = nums[i];

        /* 检查相同牌 */
        for (i = i + 1; i < 5; i++)
            if (nums[i] == nums[i - 1])
                return false;

        return imax - imin < 5;
    }
};

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int zerocnt = 0, diff = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zerocnt++;
                continue;
            }

            if (i > 0) {
                if (nums[i] == nums[i - 1])
                    return false;
                if (nums[i - 1] != 0)
                    diff += (nums[i] - nums[i - 1] - 1);
            }

        }

        return zerocnt >= diff;
    }
};
