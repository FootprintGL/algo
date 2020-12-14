

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
         * 双指针 - 滑动窗口
         * 当窗口内没有重复字母是右移right扩大窗口，并更新最长字串长度
         * 直到出现重复字母，右移left缩小窗口，指导不再包含重复字符
         */
        int n = s.length();
        if (n < 1)
            return n;

        unordered_set<char> tbl;
        int left = 0, right = 0;
        int ans = 0;

        while (right < n) {
            /* 扩大窗口直到出现重复字符 */
            while (right < n && tbl.count(s[right]) == 0) {
                tbl.insert(s[right]);
                right++;
            }
            ans = max(ans, right - left);

            /* 缩小窗口直到去除重复字符s[right] */
            while (left < right && tbl.count(s[right]) > 0) {
                tbl.erase(s[left]);
                left++;
            }
        }

        return ans;
    }
};
