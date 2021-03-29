

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        /*
         * 滑动窗口[left, right)
         */
        int res = 0;
        int left = 0, right = 0, sum = 0;

        while (right < s.length()) {
            sum += abs(s[right] - t[right]);

            //cout << left << " " << right << " " << sum << " " << maxCost << " " << res << endl;
            while (sum > maxCost) {
                /* sum超过maxCost，移动left缩小窗口 */
                sum -= abs(s[left] - t[left]);
                left++;
            }
            //cout << left << " " << right << " " << sum << endl;
            res = max(res, right - left + 1);
            /* 右移right扩大窗口 */
            right++;
        }

        return res;
    }
};
