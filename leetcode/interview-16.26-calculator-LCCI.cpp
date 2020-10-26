
class Solution {
public:
    bool isdigit(char c) {
        return c >= '0' && c <= '9';
    }

    int calculate(string s) {
        /* 
         * 堆栈
         *  1. 数字直接入栈
         *  2. 空格跳过
         *  3. + -> num入栈
         *  4. - -> -num入栈
         *  5. * -> top() * num入栈
         *  6. / -> top() / num入栈
         * 结果为栈里的元素相加
         */
        stack<int> stk;
        int res = 0, num = 0;
        int n = s.length(), i;
        char sign = '+';

        for (i = 0; i <= n; i++) { ////--->等号保证最后一个数字的处理，字符串后面会有一个‘\0‘,不会越界
            if (s[i] == ' ') {
                continue;
            } else if (isdigit(s[i])) {
                /* 计算操作书 */
                num = num * 10 + (s[i] - '0');
            } else {
                switch(sign) {
                    case '+': stk.push(num); break;
                    case '-': stk.push(-1 * num); break;
                    case '*': num = stk.top() * num; stk.pop(); stk.push(num); break;
                    case '/': num = stk.top()/num; stk.pop(); stk.push(num); break;
                    default: 
                        break;
                }
                //cout << stk.size() << " " << stk.top() << " " << i << " " << s[i] << " " << n << endl;
                num = 0;
                sign = s[i];
            }
        }
        
        /* 构建结果 */
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};


class Solution {
public:
    bool isdigit(char c) {
        return c >= '0' && c <= '9';
    }

    int calculate(string s) {
        /* 堆栈模拟 - *和/优先级比+/-高，去掉字符串中的空格 */
        string cstk;
        stack<int> dstk;

        int res = 0, ans = 0;
        int n = s.length();
        int start = 0, end = 0;
        int cur, tmp;

        if (n == 0)
            return 0;

        while (start < n) {
            //cout << start << " " << end << " " << n << endl;
            while (start < n && s[start] == ' ')
            /* 跳过空格 */
                start++;
            //cout << start << " - " << end << " " << n << endl;
            if (start == n)
                break;

            end = start;
            if (isdigit(s[start])) {
                while (end < n && isdigit(s[end]))
                    end++;

                cur = stoi(s.substr(start, end - start));
                //cout << start << " -- " << end << " " << n << " " << cur << endl;
                if (!cstk.empty()) {
                    if (cstk.back() == '*') {
                        /* 计算栈顶元素乘以cur */
                        tmp = dstk.top();
                        tmp *= cur;
                        /* 删除乘号 */
                        cstk.pop_back();
                        /* 保存计算结果 */
                        dstk.pop();
                        dstk.push(tmp);
                    } else if (cstk.back() == '/') {
                        /* 计算栈顶元素除于cur */
                        tmp = dstk.top();
                        tmp /= cur;
                        /* 删除除号 */
                        cstk.pop_back();
                        dstk.pop();
                        /* 保存计算结果 */
                        dstk.push(tmp);
                    } else {
                        dstk.push(cur);
                    }
                } else {
                    dstk.push(cur);
                }
            } else {
                /* 符号入栈 */
                if (s[start] == '+' || s[start] == '-') {
                    /* +/-号表示前面的连续乘除计算完毕 */
                    if (!cstk.empty()) {
                        /* 计算前面的加减法 */
                        int t = dstk.top();
                        dstk.pop();
                        if (cstk.back() == '+') {
                            t = dstk.top() + t;
                        } else {
                            t = dstk.top() - t;
                        }
                        cstk.pop_back();
                        /* 保存计算结果 */
                        dstk.pop();
                        dstk.push(t);
                    }
                }
                cstk.push_back(s[start]);
                end++;
            }

            start = end;
        }

        if (cstk.empty()) {
            res = dstk.top();
        } else {
            res = dstk.top();
            dstk.pop();
            if (cstk.back() == '+')
                res = dstk.top() + res;
            else
                res = dstk.top() - res;
        }

        return res;
    }
};
