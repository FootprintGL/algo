


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        /*
         * 辅助栈模拟
         * 栈符合先进后出规，给定入栈序列和弹栈序列，压入和弹出的顺序是固定的
         * 模拟入栈操作，如果栈顶元素和出栈序列当前元素是否相同，如果相同，则把符合出栈序列的元素弹栈
         * 如果则后栈空则返回true，否则返回false
         */
        stack<int> st;
        int i, j = 0;

        for (i = 0; i < pushed.size(); i++) {
            st.push(pushed[i]);
            while (!st.empty() && st.top() == popped[j]) {
                /* 栈顶元素和出栈序列当前元素相同则持续弹栈 */
                st.pop();
                j++;
            }
        }

        return st.empty();
    }
};
