
class MinStack {
public:
    /* stk1维护正常栈操作，stk2维护最小值 */
    stack<int> stk1;
    stack<int> stk2;

    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        stk1.push(x);
        if (!stk2.empty()) {
            if (x <= stk2.top()) {
                stk2.push(x);
            }
        } else {
            stk2.push(x);
        }
    }

    void pop() {
        if (stk1.top() == stk2.top())
            stk2.pop();
        stk1.pop();
    }

    int top() {
        if (stk1.empty())
            return -1;

        return stk1.top();
    }

    int getMin() {
        if (stk2.empty())
            return -1;

        return stk2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
