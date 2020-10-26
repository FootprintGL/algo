

class SortedStack {
public:
    /* 双栈 */
    stack<int> stk;
    stack<int> tmp;

    SortedStack() {
    }

    void push(int val) {
        //cout << "p- " << val << endl;
        if (stk.empty()) {
            //cout << "p-1 " << val << endl;
            stk.push(val);
        } else {
            //cout << "p-2 " << val << endl;
            while (!stk.empty() && val > stk.top()) {
                /* 把小于val的元素放入辅助栈 */
                tmp.push(stk.top());
                stk.pop();
            }
            stk.push(val);
            while (!tmp.empty()) {
                /* 把辅助栈中的元素放回主栈 */
                stk.push(tmp.top());
                tmp.pop();
            }
        }
    }

    void pop() {
        //cout << "pop- " << stk.top() << endl;
        if (!stk.empty())
            stk.pop();
    }

    int peek() {
        //cout << "peek";
        if (!stk.empty()) {
            //cout << "-1 " << stk.top() << endl;
            return stk.top();
        } else {
            //cout << "-2 " << -1 << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return stk.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
