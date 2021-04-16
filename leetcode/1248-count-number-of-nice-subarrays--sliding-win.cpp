

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        /*
         * 滑动窗口 - 双指针
         * 移动right扩大窗口，直到奇数个数为k
         * 统计第一个奇数左边偶数的个数(leftevencnt)和最后一个奇数右边偶数的个数(rightevencnt)
         * 起点可以在左边偶数中，终点可以在右边偶数中,左右可以都不取，结果为
         * (leftevencnt + 1) * (rightevencnt + 1)
         */
        int res = 0;
        int cnt = 0, n = nums.size();
        int left = 0, right = 0;

        while (right < n) {
            if (nums[right++] % 2)
                cnt++;

            if (cnt == k) {
                int leftevencnt = 0, rightevencnt = 0;
                while (right < n && nums[right] % 2 == 0) {
                    rightevencnt++;
                    right++;
                }
                while (left <= right && nums[left] % 2 == 0) {
                    leftevencnt++;
                    left++;
                }
                //cout << left << " " << right << " " << leftevencnt << " " << rightevencnt << endl;
                res += (leftevencnt + 1) * (rightevencnt + 1);

                left++;
                cnt--;
            }
        }

        return res;
    }
};
