class Solution {
public:
    int countSegments(string s) {
        int n = s.length();
        int cnt = 0;

        if (n == 0)
            return 0;

        /* 
         * 统计单词个数等同于计算单词开始下标的个数
         * 若当前下标不是空格，前一个是空格, 则为单词开始
         */

        /* 为方便处理，在开头插入一个空格 */
        s.insert(s.begin() + 0, ' ');
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != ' ' && s[i - 1] == ' ')
                cnt++;
        }

        return cnt;
    }
};


class Solution {
public:
    int countSegments(string s) {
        /* 双指针 */
        int n = s.length();
        int cnt = 0;
        int l, r;

        if (n == 0)
            return 0;

        l = r = 0;
        while (r < n) {
            /* 跳过空格 */
            while (l < n && s[l] == ' ')
                l++;

            if (l == n)
                break;

            r = l + 1;
            while (r < n && s[r] != ' ')
                r++;

            /* 找到新单词 */
            cnt++;
            l = r;
        }

        return cnt;
    }
};
