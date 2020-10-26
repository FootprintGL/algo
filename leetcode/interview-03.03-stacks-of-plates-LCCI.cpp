

class StackOfPlates {
public:
    vector<stack<int>> stks;
    int cap;

    StackOfPlates(int cap) {
        this->cap = cap;
    }

    void push(int val) {
        stack<int> cur;

        if (cap == 0)
            return;

        if (stks.empty() || stks.back().size() == cap) {
            cur.push(val);
            stks.push_back(cur);
            return;
        } else {
            stks.back().push(val);
        }
    }

    int pop() {
        return popAt(stks.size() - 1);
    }

    int popAt(int index) {
        int res = -1;

        if (index >= 0 && index < stks.size()) {
            res = stks[index].top();
            stks[index].pop();
            if (stks[index].empty())
                stks.erase(stks.begin() + index);
        }

        return res;
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */
