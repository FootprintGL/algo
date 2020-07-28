


/* 动态规划 - 贪心 + 二分 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> tail;
        int i, j, k;
        int left, right, mid;

        if (len == 0)
            return 0;

        /*
         * 动态规划
         * tail[i]表示以长度为i + 1的子序列结尾最小的元素
         * 如果num[i]大于tail[len], len = len + 1, tail[len] = num[i]
         * 如果num[i]小于tail[len], 在tail[0-len]搜索地一个大于num[i]s的元素，并更新为nums[i]
         * tail为升序数组，可以用二分查找搜索(O(nlogn)) 
         * tail数组的长度即为最长子序列的长度
         */
        tail.push_back(nums[0]);
        for (i = 1; i < len; i++) {
            if (nums[i] > tail[tail.size() - 1]) {
                tail.push_back(nums[i]);
            } else {
                left = 0;
                right = tail.size() - 1;
                while (left < right) {
                    /* 搜索第一个大于nums[i]的元素 */
                    mid = left + (right - left) / 2;
                    if (nums[i] > tail[mid]) {
                        left = mid + 1;
                    } else if (nums[i] < tail[mid]) {
                        right = mid - 1;
                    } else {
                        break;
                    }
                }
                if (nums[i] > tail[left]) {
                    tail[left + 1] = nums[i];
                } else if (nums[i] < tail[left]) {
                    tail[left] = nums[i];
                }
            }
        }

        return tail.size();
    }
};



class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res, tmp;
        int len = nums.size();
        vector<int> dp(len, 0);
        int i, j;

        if (len == 0)
            return 0;

        /*
         * 动态规划
         * dp[i]表示以nums[i]结尾的最长上升子序列长度
         * dp[i] = max(dp[j]) + 1 j为[0-i]中所有nums[j] < nums[i]
         * 边统计边更新最长子序列长度
         */
        res = dp[0] = 1;
        for (i = 1; i < len; i++) {
            dp[i] = 1;
            j = i - 1;
            while (j >= 0) {
                while (j >= 0 && nums[j] >= nums[i])
                    j--;
                if (j >= 0 && dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
                j--;
            }

            if (dp[i] > res)
                    res = dp[i];
        }

        return res;
    }
};
