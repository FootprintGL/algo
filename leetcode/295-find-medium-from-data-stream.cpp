


/*
 * 堆排序
 * 维护两个优先队列，一个用于存储较小一半数字的最大堆lo，一个用于存储较大一半数字的最小堆hi
 * 最大堆lo允许存储的元素最多比最小堆hi多一个
 * 当完全平衡时，中间值从两个堆的顶部产生，否则最大堆的顶部保留合法的中间值
 * 添加一个数num
 *      将num添加到最大堆lo，lo收到一个新元素,必须对hi做平衡处理，从lo中移出一个元素放入hi
 *      最小堆hi可能会比最大堆lo保留更多的元素，从hi中移出一个元素放入lo
 */
class MedianFinder {
public:
    /* 最大堆 */
    priority_queue<int> lo;
    /* 最小堆 */
    priority_queue<int, vector<int>, greater<int>> hi;

    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        if (lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian() {
        return lo.size() == hi.size() ? (lo.top() + hi.top()) * 0.5 : (double)lo.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
