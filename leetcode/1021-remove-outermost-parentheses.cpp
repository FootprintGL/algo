

class Solution {
public:
    string removeOuterParentheses(string S) {
        /*
         * 栈
         * 左括号入栈，右括号弹栈
         * 入栈时栈空，为外层左括号
         * 弹栈后栈空，为外层右括号
         */
        string stk;
        string res;

        for (int i = 0; i < S.length(); i++) {
            char c = S[i];
            if (c == '(') {
                if (!stk.empty())
                    res += c;
                stk.push_back(c);
            } else {
                stk.pop_back();
                if (!stk.empty())
                    res += c;
            }
        }

        return res;
    }
};
