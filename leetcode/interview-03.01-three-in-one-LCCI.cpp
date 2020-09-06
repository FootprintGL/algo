

class TripleInOne {
public:
    vector<int> st;
    vector<pair<int, int>> regs;
    pair<int, int> reg;
    int stsize;

    TripleInOne(int stackSize) {
        regs.resize(3);
        st.resize(stackSize * 3);
        stsize = stackSize;
        regs[0].first = regs[0].second = 0;
        regs[1].first = regs[1].second = stackSize;
        regs[2].first = regs[2].second = 2 * stackSize;
    }

    void push(int stackNum, int value) {
        //cout << "push-" << stackNum << " " << value << " " << regs[stackNum].second << endl;
        if (regs[stackNum].second == regs[stackNum].first + stsize) {
            //cout << "stack-" << stackNum << " full" << endl << endl;;
            return;
        }

        st[regs[stackNum].second] = value;
        regs[stackNum].second++;
        //cout << stackNum << " " << value << " " << regs[stackNum].second << endl;
    }

    int pop(int stackNum) {
        //cout << "pop-" << stackNum << " " << regs[stackNum].second << endl;
        if (isEmpty(stackNum)) {
            return -1;
        }

        int ans = st[regs[stackNum].second - 1];
        regs[stackNum].second--;
        return ans;
    }

    int peek(int stackNum) {
        //cout << "peek-" << stackNum << " " << regs[stackNum].second << endl;
        if (isEmpty(stackNum))
            return -1;

        return st[regs[stackNum].second - 1];
    }

    bool isEmpty(int stackNum) {
        bool ret = (regs[stackNum].first == regs[stackNum].second);
        //cout << "stack-" << stackNum << " empty-" << ret << endl << endl;;
        return ret;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */
