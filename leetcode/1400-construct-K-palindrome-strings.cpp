

class Solution {
public:
    bool canConstruct(string s, int k) {
        /*
         * 偶数个相同字符可以加入回文串构成新的回文串
         * 奇数个相同字符a和奇数个相同字符b无法构成回文串
         *      1. 如果s的长度小于k，肯定无法构成k个回文串
         *      2. 如果含有奇数个的字母数量大于k，则无法构成k个回文串
         *      3. 否则，可以构成k个回文串
         */
        int len = s.length();

        if (len < k)
            return false;

        /* 统计每个字母出现的次数 */
        int cnt[26] = {0};
        for (auto &c : s)
            cnt[c - 'a']++;

        /* 统计出现奇数次字母的个数 */
        int oddnum = 0;
        for (int i = 0; i < 26; i++)
            if (cnt[i] % 2)
                oddnum++;

        return oddnum <= k;
    }
};
