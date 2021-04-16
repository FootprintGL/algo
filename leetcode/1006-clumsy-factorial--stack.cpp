

class Solution {
public:
    int clumsy(int N) {
        /*
         * 堆栈
         * 先计算乘除，再计算加减
         * 1 遇到乘号时，取栈顶元素求乘积再入栈
         * 2 遇到除号时，取栈顶元素求商再入栈
         * 3 加号，直接入栈
         * 4 减号，相反数入栈
         * 结果为栈内元素的和
         */
        stack<int> stk;
        int index = 0;
        int tmp;

        stk.push(N);
        N--;
        while (N > 0) {
            if (index == 0) {
                tmp = N * stk.top();
                stk.pop();
                stk.push(tmp);
            } else if (index == 1) {
                tmp = stk.top() / N;
                stk.pop();
                stk.push(tmp);
            } else if (index == 2) {
                stk.push(N);
            } else if (index == 3) {
                stk.push(-N);
            }
            index++;
            index %= 4;
            N--;
        }

        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }

        return res;
    }
};
