

class MyCircularDeque {
public:
    vector<int> qu;
    int capability;
    int front;
    int rear;

    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        capability = k + 1;
        qu.resize(capability);
        /* front和rear相等时队列为空，(rear + 1) % capability == front时队列满 */
        front = rear = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull())
            return false;
        front--;
        if (front == -1)
            front = capability - 1;
        qu[front] = value;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull())
            return false;
        qu[rear] = value;
        rear++;
        rear %= capability;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty())
            return false;

        front++;
        front %= capability;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty())
            return false;
        rear--;
        if (rear == -1)
            rear = capability - 1;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty())
            return -1;
        return qu[front];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty())
            return -1;
        int idx = rear - 1;
        if (idx == -1)
            idx = capability - 1;
        return qu[idx];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return front == rear;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (rear + 1) % capability == front;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
