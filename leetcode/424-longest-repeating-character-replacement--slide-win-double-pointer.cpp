

class Solution {
public:
    int characterReplacement(string s, int k) {
        /*
         * 滑动窗口 - 双指针
         * 不需要每次都去更新hismaxcnt, 当hismaxcnt和k一定时，区间的最大长度也就定了。
         * 找到一个hismaxcnt之后，就能说找到了一个长度为d = hismaxcnt + k的合法区间，最终答案一定不小于d
         * 当发现继续向右扩展right不合法时，我们不需要不断右移left，只需要保持区间长度为d向有滑行
         * 如果有某个合法区间大于d，一定在某个时刻存在cnt[t] + 1 > max_count, 这是再去更新hismaxcnt即可
         */
        /* 记录当前窗口字母出现的次数 */
        vector<int> cnt(26, 0);
        int left = 0, right = 0;
        /* 记录字符出现次数最多的那个字符的次数 */
        int hismaxcnt = 0;

        for (right = 0; right < s.length(); right++) {
            cnt[s[right] - 'A']++;
            /* 比较之前记录的最大数 和 当前字符的数量 */
            hismaxcnt = max(hismaxcnt, cnt[s[right] - 'A']);
            /* 当前窗口大小 大于 历史最多字符个数 + k */
            if (right - left + 1 > hismaxcnt + k) {
                /* 向右滑动窗口 */
                cnt[s[left] - 'A']--;
                left++;
            }
        }

        return s.length() - left;
    }
};
