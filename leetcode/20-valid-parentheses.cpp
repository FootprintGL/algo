

class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        stack<char> stk;

        if (len % 2)
            return false;
        
        for (int i = 0; i < len; i++) {
            //cout << s[i] << endl;
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
                //cout << "push: " << s[i] << endl;
            } else if (s[i] == ')') {
                if (stk.empty() || stk.top() != '(')
                    return false;
                //cout << "pop: " << stk.top() << endl;
                stk.pop();
            } else if (s[i] == ']') {
                if (stk.empty() || stk.top() != '[')
                    return false;
                stk.pop();
            } else if (s[i] == '}') {
                if (stk.empty() || stk.top() != '{')
                    return false;
                stk.pop();
            }
        }

        return stk.empty();
    }
};


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        if (s.size() == 0)
            return true;

        for (auto i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty())
                    return false;
                else if (s[i] == ')') {
                    if (st.top() != '(')
                        return false;
                    else 
                        st.pop();
                } else if (s[i] == ']') {
                    if (st.top() != '[')
                        return false;
                    else
                        st.pop();
                } else if (s[i] == '}') {
                    if (st.top() != '{')
                        return false;
                    else
                        st.pop();
                }
            }
        }

        return st.empty();
    }
};

