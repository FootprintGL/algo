

class Solution {
public:
    bool isdigit(const char &c) {
        return c >= '0' && c <= '9';
    }

    int myAtoi(string s) {
        /* 防止整数溢出 */
        long long res = 0;
        int n = s.length();

        /* 去掉开头的空格 */
        int start = 0;
        while (start < n && s[start] == ' ')
            start++;

        if (start == n)
            return 0;

        int sign = 0;
        if (s[start] == '+') {
            sign = 1;
            start++;
        } else if (s[start] == '-') {
            sign = -1;
            start++;
        } else if (!isdigit(s[start])) {
            /* 不是有效数字 */
            return 0;
        }

        /* 去掉前导0 */
        while (start < n && s[start] == '0')
            start++;

        int cnt = 0;
        while (start < n) {
            if (!isdigit(s[start]))
                break;
            res = res * 10 + s[start] - '0';
            cnt++;
            if (cnt > 10)
            /* 整型数位小于等于10 */
                break;
            start++;
        }

        /* 整数边界处理 */
        if (sign == -1) {
            res *= sign;
            if (res < INT_MIN)
                res = INT_MIN;
        } else {
            if (res > INT_MAX)
                res = INT_MAX;
        }

        return res;
    }
};
