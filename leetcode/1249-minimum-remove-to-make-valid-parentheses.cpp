

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        /*
         * 从左往右遍历去除多余的右括号
         * 从右向左遍历去除多余的左括号
         */
        int balance = 0;

        /* 从左往右遍历 - 去掉多余的右括号 */
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                balance++;
            } else if (s[i] == ')') {
                if (balance == 0) {
                    s.erase(i, 1);
                    i--;
                    continue;
                }
                balance--;
            }
        }

        //cout << s << endl;

        /* 从右向左遍历 - 去掉多余的左括号 */
        balance = 0;
        for (int i = s.length(); i >= 0; i--) {
            if (s[i] == ')') {
                balance++;
            } else if (s[i] == '(') {
                if (balance == 0) {
                    s.erase(i, 1);
                    continue;
                }
                balance--;
            }
        }

        //cout << s << endl;

        return s;
    }
};


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        /*
         * 哈希表存放要移除的括号的坐标
         * 遇到左括号balance++, 右括号balance--
         */
        stack<int> stk;
        unordered_set<int> idx;
        int balance = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
                balance++;
            } else if (s[i] == ')'){
                if (balance == 0) {
                    /* 多余的右括号，需要移除 */
                    idx.insert(i);
                    continue;
                }
                stk.pop();
                balance--;
            }
        }

        while (!stk.empty()) {
            /* 多余的左括号，需要移除 */
            idx.insert(stk.top());
            stk.pop();
        }

        string res;
        for (int i = 0; i < s.length(); i++)
            if (idx.count(i) == 0)
                res.push_back(s[i]);

        return res;
    }
};
