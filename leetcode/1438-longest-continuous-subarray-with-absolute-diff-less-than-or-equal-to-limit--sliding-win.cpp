

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        /*
         * 滑动窗口
         * 需要知道窗口内的最大值和最小值，使用map自带的排序功能
         * 如果窗口内最大绝对差大于limit，缩小窗口，否则扩大窗口
         */
        map<int, int> tbl;
        int n = nums.size();
        int left = 0, right = 0;
        int res = 0;

        while (right < n) {
            tbl[nums[right]]++;
            while (tbl.rbegin()->first - tbl.begin()->first > limit) {
                /* 窗口内最大绝对差大于limit，右移left缩小窗口 */
                tbl[nums[left]]--;
                if (tbl[nums[left]] == 0)
                    tbl.erase(nums[left]);
                left++;
            }
            /* 更新结果并扩大窗口 */
            res = max(res, right - left + 1);
            right++;
        }

        return res;
    }
};
