

class Solution {
public:
    bool isdigit(char c) {
        return c >= '0' && c <= '9';
    }

    int calculate(string s) {
        /* 存放数字 */
        stack<int> stk;
        char sign = '+';
        int cur = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (isdigit(c))
                /* 先算c - '0'防止整数溢出 */
                cur = cur * 10 + (c - '0');

            if ((!isdigit(c) && c != ' ')|| i == s.length() - 1){
                if (sign == '+') {
                    stk.push(cur);
                } else if (sign == '-') {
                    /* 减法转换成加法 */
                    stk.push(-cur);
                } else {
                    /* 乘除法直接计算，结果放入堆栈 */
                    int tmp = sign == '*' ? stk.top() * cur : stk.top() / cur;
                    stk.pop();
                    stk.push(tmp);
                }
                cur = 0;
                sign = c;
            }
        }

        /* 累加栈内元素 */
        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }

        return res;
    }
};
