

class Solution {
public:
    int minAddToMakeValid(string S) {
        /*
         * 堆栈
         * 当前为‘)‘
         *      如果栈为空，需要添加一个’(’
         *      如果栈不为空，弹出一个'('
         * 当前为'(', 入栈等待')'消除
         * 最后留在栈里'('的数量都需要添加‘)‘消除
         */
        int res = 0;
        string stk;

        for (auto &c : S) {
            if (c == '(') {
                stk.push_back(c);
            } else {
                if (!stk.empty()) {
                    stk.pop_back();
                } else {
                    res++;
                }
            }
        }

        return res + stk.size();
    }
};
