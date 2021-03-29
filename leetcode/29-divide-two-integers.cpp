

class Solution {
public:
    /* 摆竖式 - 移位 + 减法 */
    int divide(int dividend, int divisor) {
        /* 特殊情况 */
        if (dividend == divisor)
            return 1;
        if (divisor == 1)
            return dividend;
        if (dividend == 0)
            return 0;
        /* 边界处理 */
        if (divisor == INT_MIN)
            return 0;

        /* INT_MIN取绝对值会移出，这里先加上一个divisor */
        bool flag = dividend == INT_MIN;
        if (flag)
            dividend += abs(divisor);

        /* 是否同正负 */
        bool same = dividend >= 0 == divisor >= 0;
        dividend = abs(dividend);
        divisor = abs(divisor);

        //cout << dividend << " " << divisor << endl;
        /* 模拟竖式乘法 */
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int temp = dividend >> i;
            res = (res << 1) + (temp >= divisor);
            if (temp >= divisor)
                dividend -= divisor << i;
        }
        //cout << res << endl;

        if (flag)
            return same ? (res != INT_MAX ? res + 1 : res) : -res - 1;
        else
            return same ? res : -res;
    }
};
