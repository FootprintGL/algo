

class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0, cnt = 0, i;

        /* 遇到L, cnt++, 遇到R cnt--, cnt为0时表示平衡子串结束，ans++ */
        for (i = 0; i < s.length(); i++) {
            if (s[i] == 'L') {
                if (++cnt == 0)
                    ans++;
            } else {
                if (--cnt == 0)
                    ans++;
            }
        }

        return ans;
    }
};

class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0, cnt = 0, i;
        char c;

        for (i = 0; i < s.length(); i++) {
            if (cnt == 0) {
                /* 平衡子串开始 */
                c = s[i];
                cnt = 1;
                continue;
            }

            if (s[i] == c) {
                /* 和平衡子串首字符相同 */
                cnt++;
            } else {
                /* 和平衡子串首字符不同 */
                cnt--;
                if (cnt == 0) {
                    /* 平衡字串结束 */
                    ans++;
                }
            }
        }

        return ans;
    }
};
