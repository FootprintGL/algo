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

