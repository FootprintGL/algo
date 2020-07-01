class CQueue {
    stack<int> s1, s2;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        int res;

        if (!s2.empty()) {
            res = s2.top();
            s2.pop();
        } else if (!s1.empty()) {
            while (!s1.empty()) {
                res = s1.top();
                s2.push(res);
                s1.pop();
            }
            s2.pop();
        } else if (s1.empty()) {
            res = -1;
        }

        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
