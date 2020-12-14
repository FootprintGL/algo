


class BrowserHistory {
public:
    /*
     * 堆栈
     * 用一个栈记录浏览历史，pos记录当前网页在栈中的位置
     * 每次back, forward只更新pos，visit会把浏览历史前进的记录删除
     * visit先根据pos跟新栈顶指针top，然后url在入栈
     */
    string data[5001] = {""};
    int pos;
    int top;
    BrowserHistory(string homepage) {
        pos = 0;
        top = 1;
        data[0] = homepage;
    }

    void visit(string url) {
        pos++;
        top = pos;
        data[top++] = url;
    }

    string back(int steps) {
        if (steps > pos)
            steps = pos;
        pos = pos - steps;
        return data[pos];
    }

    string forward(int steps) {
        if (steps > top - pos - 1)
            steps = top - pos - 1;
        pos += steps;
        return data[pos];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */



class BrowserHistory {
public:
    /* 历史数据 */
    vector<string> data;
    /* 当前页面索引 */
    int cur;
    /* 历史记录结束索引[0, end) - 左闭右开 */
    int end;

    BrowserHistory(string homepage) {
        data.resize(5001);
        data[0] = homepage;
        cur = 0;
        end = 1;
    }

    void visit(string url) {
        cur++;
        data[cur] = url;
        end = cur + 1;
    }

    string back(int steps) {
        while (steps-- && cur >= 0)
            cur--;

        if (cur < 0)
        /* 第一个 */
            cur++;

        return data[cur];
    }

    string forward(int steps) {
        while (steps-- && cur != end)
            cur++;

        if (cur == end)
        /* 最后一个 */
            cur--;

        return data[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
