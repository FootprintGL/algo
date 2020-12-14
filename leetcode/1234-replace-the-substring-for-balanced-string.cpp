

class Solution {
public:
    int balancedString(string s) {
        /*
         * 双指针 - 滑动窗口
         * 题目要求每个字母的个数为均值，对于出现次数多于均值的字母需要替换掉，假设差值为cnt[c] - aver
         * 替换的字串必须包含大于等于cnt[c] - aver个相应字符，多出来的保持原字符
         * 两个指针维护一个窗口[l, r], 如果[l, r]满足条件(大于等于要替换的字母个数)，则右移l缩小窗口，并记录最小值
         * 如果[l, r]不满足条件，则右移r加入更多字符
         * 也可以考虑窗口外的元素，把多的元素放在窗口中，窗口外的元素肯定小于等于aver
         * 以此为依据来进行窗口滑动
         */
        int n = s.size(), aver = n / 4, ans = n;
        /* 初始化为-aver, 统计后的结果大于0的为多出来的 */
        vector<int> cnt(26, 0);
        int left = 0, right = 0;

        /* 统计每个字母个数 */
        for (auto &c : s)
            cnt[c - 'A']++;

        while (right < n) {
            /* 扩大窗口 - 窗口外元素变多 */
            cnt[s[right] - 'A']--;
            while (left < n && cnt['Q' - 'A'] <= aver && cnt['W' - 'A'] <= aver && cnt['E' - 'A'] <= aver && cnt['R' - 'A'] <= aver) {
                ans = min(ans, right - left + 1);
                /* 缩小窗口 - 窗口外元素变少 */
                cnt[s[left] - 'A']++;
                left++;
            }
            right++;
        }

        return ans;
    }
};



class Solution {
public:
    int balancedString(string s) {
        /*
         * 双指针 - 滑动窗口
         * 题目要求每个字母的个数为均值，对于出现次数多于均值的字母需要替换掉，假设差值为cnt[c] - aver
         * 替换的字串必须包含大于等于cnt[c] - aver个相应字符，多出来的保持原字符
         * 两个指针维护一个窗口[l, r], 如果[l, r]满足条件(大于等于要替换的字母个数)，则右移l缩小窗口，并记录最小值
         * 如果[l, r]不满足条件，则右移r加入更多字符
         */
        int n = s.size(), aver = n / 4, ans = n;
        /* 初始化为-aver, 统计后的结果大于0的为多出来的 */
        vector<int> cnt(26, -1 * aver);
        vector<int> cur(26, 0);
        int left = 0, right = 0;
        int needcnt = 0, matchcnt = 0;

        /* 统计每个字母个数 */
        for (auto &c : s)
            cnt[c - 'A']++;

        /* 计算有几个字符多出来需要被替换 */
        for (auto &t : cnt)
            if (t > 0)
                needcnt++;

        /* 已经平衡 */
        if (needcnt == 0)
            return 0;

        while (right < n) {
            char c = s[right];
            if (cnt[c - 'A'] > 0) {
                cur[c - 'A']++;
                if (cur[c - 'A'] == cnt[c - 'A'])
                    matchcnt++;
            }

            while (left <= n && matchcnt == needcnt) {
                ans = min(ans, right - left + 1);
                char cl = s[left];
                if (cnt[cl - 'A'] > 0) {
                    cur[cl - 'A']--;
                    if (cur[cl - 'A'] < cnt[cl - 'A'])
                        matchcnt--;
                }
                /* 窗口内字串满足条件，缩小窗口 */
                left++;
            }
            /* 窗口内字串不满足条件，扩大窗口 */
            right++;
        }

        return ans;
    }
};
