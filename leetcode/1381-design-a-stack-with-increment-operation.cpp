

class CustomStack {
public:
    vector<int> stk;
    int maxSize;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }

    void push(int x) {
        if (stk.size() == maxSize)
            return;
        stk.push_back(x);
    }

    int pop() {
        if (stk.empty())
            return -1;
        int res = stk.back();
        stk.pop_back();
        return res;
    }

    void increment(int k, int val) {
        for (int i = 0; i < k && i < stk.size(); i++)
            stk[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
