
class Solution {
public:
    int longestSubstring(string s, int k) {
        /*
         * 滑动窗口
         * 该题不具有二分属性，无法直接使用滑动窗口
         * 假设有长度t的字串满足要求, t + 1是否一定满足或一定不满足
         * t + 1满足与否取决于t + 1位置的字符在不在原有区间内
         * 双指针 - 当一个指针确定在某个位置，另外一个指针能够落在某个明确的
         * 分割点，使左半部分满足，右半部分不满足
         * 可以枚举最大长度所包含的字符类型数量，答案为[1, 26]
         * 当确定了长度所包含得字符种类数量时，区间重新具有二分属性
         * 1 右端点右移必然会导致字符类型数量增加或不变
         * 2 左端点右移必然会导致字符类型数量减少或不变
         * 如何判断某个字符串内字符都出现了至少k次
         * 维护一个计数器less，代表当前出现次数小于k的字符的数量，每次移动窗口边界，
         * 只会让某个字符的出现次数加一或减一，对于移动有边界的情况
         * 1 当某个字符出现次数从0到1，less++
         * 2 当某个字符出现次数从k - 1到k时，less--
         */
        int n = s.length();
        int res = 0;
        if (k == 1)
            return n;

        for (int t = 1; t <= 26; t++) {
            int l = 0, r = 0;
            /* 窗口内总的字符类型数量 */
            int tot = 0;
            /* 窗口内数量小于k的字符类型数量 */
            int less = 0;
            vector<int> cnt(26, 0);

            while (r < n) {
                cnt[s[r] - 'a']++;
                if (cnt[s[r] - 'a'] == 1) {
                    /* 出现一个新的字符类型 */
                    tot++;
                    less++;
                }
                if (cnt[s[r] - 'a'] == k)
                    /* 一个字符类型数量达到k */
                    less--;

                while (tot > t) {
                    /* 右移l，缩小窗口 */
                    cnt[s[l] - 'a']--;
                    if (cnt[s[l] - 'a'] == 0) {
                        tot--;
                        less--;
                    }
                    if (cnt[s[l] - 'a'] == k - 1)
                        less++;
                    l++;
                }

                if (less == 0)
                /* 更新结果 - 窗口满足需求 - 窗口内所有字符出现次数都大于等于k */
                    res = max(res, r - l + 1);

                /* 右移r，扩大窗口 */
                r++;
            }
        }

        return res;
    }
};


class Solution {
public:
    int helper(string &s, int l, int r, int k) {
        //cout << l << " " << r << " " << k << endl;
        if (r - l + 1 < k)
        /* 字串长度小于k */
            return 0;

        /* 统计[l, r]字母出现的次数 */
        vector<int> cnt(26, 0);
        int i;
        for (i = l; i <= r; i++)
            cnt[s[i] - 'a']++;

        /* 寻找分割点 */
        int split = 0;
        for (i = 0; i < 26; i++) {
            if (cnt[i] > 0 && cnt[i] < k) {
                split = i + 'a';
                break;
            }
        }

        if (split == 0)
        /* [l, r]字串满足要求 */
            return r - l + 1;

        int res = 0;
        i = l;
        while (i <= r) {
            while (i <= r && s[i] == split)
                i++;

            if (i > r)
            /* [i,r]全部为split */
                break;

            /* 搜索不含split的字串 */
            int start = i;
            while (i <= r && s[i] != split)
                i++;

            /* 在字串中递归搜索 */
            res = max(res, helper(s, start, i - 1, k));
        }

        return res;
    }

    int longestSubstring(string s, int k) {
        /*
         * 分治
         * 对于字符串s，如果某个字符ch出现次数小于k，任何包含ch的字串都不满足需求
         * 将字符串按ch分成若干段，满足条件的最长字串一定出现在某个切分的段内
         */
        return helper(s, 0, s.size() - 1, k);
    }
};
