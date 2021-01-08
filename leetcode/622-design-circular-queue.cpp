

class MyCircularQueue {
public:
    /*
     * 数组长度固定，只要知道队首index和队列长度count，就可以得到队尾的index
     * tailidx = (headidx + count - 1) % capability
     */
    vector<int> qu;
    int capability;
    int headidx;
    int count;

    MyCircularQueue(int k) {
        capability = k;
        headidx = count = 0;
        qu.resize(k);
    }

    bool enQueue(int value) {
        if (isFull())
            return false;
        count++;
        int tailidx = (headidx + count - 1) % capability;
        qu[tailidx] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;
        headidx++;
        headidx %= capability;
        count--;
        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;
        return qu[headidx];
    }

    int Rear() {
        if (isEmpty())
            return -1;
        int tailidx = (headidx + count - 1) % capability;
        return qu[tailidx];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capability;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
