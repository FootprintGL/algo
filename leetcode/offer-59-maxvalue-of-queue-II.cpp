class MaxQueue {
public:
    queue<int> qu;
    /* 单调递减队列 - 队列先进先出，保存单调递增区间最大值 */
    deque<int> dqmax;

    MaxQueue() {

    }
    
    int max_value() {
        if (qu.empty())
            return -1;
        
        return dqmax.front();
    }
    
    void push_back(int value) {
        qu.push(value);
        while (!dqmax.empty() && dqmax.back() <= value) {
            dqmax.pop_back();
        }
        dqmax.push_back(value);
    }
    
    int pop_front() {
        int res;
        if (qu.empty())
            return -1;
        
        res = qu.front();
        qu.pop();

        if (res == dqmax.front())
            dqmax.pop_front();
        
        return res;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
