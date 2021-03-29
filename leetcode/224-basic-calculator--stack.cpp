
class Solution {
public:
    int len;

    bool isdigit(char c) {
        return c >= '0' && c <= '9';
    }

    int helper(string s, int &start) {
        vector<int> stk;
        int sign = '+';
        int cur = 0;

        for (; start < len; start++) {
            if (isdigit(s[start]))
                cur = 10 * cur + (s[start] - '0');
            
            if (s[start] == '(') {
                cur = helper(s, ++start);
                start++;
            }

            //cout << start << " " << s[start] << " " << len << endl;

            if ((!isdigit(s[start]) && s[start] != ' ') || start == len - 1) {
                //cout << start << " && " << sign << " " << len << endl;
                if (sign == '+') {
                    stk.push_back(cur);
                    //cout << "push: " << cur << endl;
                } else if (sign == '-') {
                    stk.push_back(-cur);
                } else if (sign == '*') {

                } else if (sign == '/') {

                }
                cur = 0;
                sign = s[start];
            }

            if (s[start] == ')')
                break;
        }

        //cout << stk.size() << endl;
        int res = 0;
        for (auto &num : stk)
            res += num;

        return res;
    }

    int calculate(string s) {
        /*
         * 堆栈 + 递归
         * 括号具有递归属性 3 * (4 - 5 / 2) - 6
         *      calculate(3 * (4 - 5 / 2) - 6) -> 3 * calculate(4 - 5 / 2) - 6
         * 可以将括号中的算式简化成一个数字
         * 遇到‘(‘开始递归，遇到’)’结束递归
         */
        len = s.length();
        int start = 0;
        return helper(s, start);
    }
};




class Solution {
public:
    bool isdigit(char c) {
        return c >= '0' && c <= '9';
    }

    int calculate(string s) {
        /*
         * 堆栈
         * 符号和后面的数看成一个数字1 + 3 - 2 -> 1 + 3 + (-2)
         *
         *
         */
        int sign = 1, cur = 0, res = 0;
        vector<int> stk;
        int len = s.length();

        for (int i = 0; i < len; i++) {
            char c = s[i];

            //cout << i << " " << c << " " << cur << " " << sign << " " << res << endl;
            if (isdigit(c)) {
                /* 提取当前数字 */
                cur = 0;
                while (i < len && isdigit(s[i])) {
                    cur = cur * 10 + (s[i] - '0');
                    i++;
                }
                /* i指向数字的下一个字符 - 回退1个 */
                i--;
                res = res + sign * cur;
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                /* 前面结果和符号入栈 */
                stk.push_back(res);
                stk.push_back(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                /* 括号里面结果和前面的结果相加 */
                res *= stk.back();
                stk.pop_back();
                res += stk.back();
                stk.pop_back();
            }
        }

        return res;
    }
};
