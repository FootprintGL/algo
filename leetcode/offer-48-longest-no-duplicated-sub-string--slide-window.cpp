

class Solution {
public:
    /* 双指针 - 滑动窗口 */
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        /* 统计字母个数 */
        unordered_map<char, int> cnt;
        int left = 0, right = 0;
        int n = s.length();

        if (n == 0)
            return 0;

        while (right < n) {
            if (cnt[s[right]] == 1) {
                /* 缩小窗口 - 前面已经出现过，移动left知道它移出窗口 */
                while (left < right && cnt[s[right]] == 1) {
                    cnt[s[left]]--;
                    left++;
                }
                cnt[s[right]]++;
            } else {
                /* 扩大窗口 - 右移right并更新结果 */
                cnt[s[right]]++;
                if (right - left + 1 > res)
                    res = right - left + 1;
            }
            right++;
        }

        return res;
    }
};
