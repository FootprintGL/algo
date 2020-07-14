class MyStack {
public:
    /* 
     * 两个队列之间来回切换，
     * top/pop时，把活动队列元素移到备用队列，保留最后一个元素
     * 即为stack的top栈顶元素
     */
    queue<int> list1;
    queue<int> list2;
    /* active为1时，list1为活动list，active为0时，list2为活动list */
    bool active;
    /** Initialize your data structure here. */
    MyStack() {
        active = true;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (active)
            list1.push(x);
        else
            list2.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res;
        if (active) {
            while (list1.size() > 1) {
                list2.push(list1.front());
                list1.pop();
            }
            res = list1.front();
            list1.pop();
        } else {
            while (list2.size() > 1) {
                list1.push(list2.front());
                list2.pop();
            }
            res = list2.front();
            list2.pop();
        }
        active = !active;

        return res;
    }
    
    /** Get the top element. */
    int top() {
        int res;
        if (active) {
            while (list1.size() > 1) {
                list2.push(list1.front());
                list1.pop();
            }
            res = list1.front();
        } else {
            while (list2.size() > 1) {
                list1.push(list2.front());
                list2.pop();
            }
            res = list2.front();
        }

        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (list1.empty() && list2.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
