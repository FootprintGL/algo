

class Solution {
public:
    bool isoperator(string &s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }

    int evalRPN(vector<string>& tokens) {
        vector<int> stk;

        for (auto &s : tokens) {
            if (isoperator(s)) {
                /* 拿出栈顶两个数计算，结果入栈 */
                int t1 = stk.back();
                stk.pop_back();
                int t2 = stk.back();
                stk.pop_back();
                //cout << t2 << " " << s << " " << t1 << " = ";

                switch (s[0]) {
                    case '+':
                        t2 += t1;
                        break;
                    case '-':
                        t2 -= t1;
                        break;
                    case '*':
                        t2 *= t1;
                        break;
                    case '/':
                        t2 /= t1;
                        break;
                    default:
                        cout << "invalid input" << endl;
                }
                //cout << t2 << endl;
                stk.push_back(t2);
            } else {
                /* 数字 - 直接入栈 */
                stk.push_back(stoi(s));
            }
        }

        return stk.empty() ? 0 : stk.back();
    }
};
