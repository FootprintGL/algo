

class Solution {
public:
    bool isdigit(char c) {
        return c >= '0' && c <= '9';
    }

    int strToInt(string str) {
        int sign = 1;
        /* 防止溢出 */
        long res = 0;
        bool valid = false;
        int n = str.length();

        //cout << INT_MAX << " " << INT_MIN << endl;

        if (n == 0)
        /* 空串 */
            return res;

        /* 跳过开头空格 */
        int start = 0;
        while (start < n && str[start] == ' ')
            start++;

        if (start == n)
        /* 全空格串 */
            return res;

        if (!isdigit(str[start]) && str[start] != '+' && str[start] != '-')
        /* 第一个非空字符非法 */
            return res;

        /* 处理符号位 */
        if (str[start] == '-') {
            sign = -1;
            start++;
        } else if (str[start] == '+') {
            sign = 1;
            start++;
        }

        /* 处理数字部分 */
        int cnt = 0;
        while (start < n) {
            if (!isdigit(str[start]))
                break;

            res = res * 10 + str[start] - '0';
            start++;
            if (res != 0) {
                /* 跳过开始的0 - 0000000000012345678 */
                cnt++;
                if (cnt > 10)
                /* 整数溢出 - 整数范围: -2147483648 ~ 2147483647*/
                    break;
            }
        }

        /* 符号位 */
        res *= sign;

        /* 溢出情况 */
        if (res < INT_MIN)
            res = INT_MIN;
        else if (res > INT_MAX)
            res = INT_MAX;

        return res;
    }
};
