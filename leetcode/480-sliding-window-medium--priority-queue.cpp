

class DualHeap {
    /* 最大堆 - 放较小的一半 */
    priority_queue<int> small;
    /* 最小堆 - 放较大的一半 */
    priority_queue<int, vector<int>, greater<int>> large;
    /* 保持待删除的元素和个数 */
    unordered_map<int, int> delayed;
    /* 最大堆的元素个数 - 需要减去待删除的元素 */
    int smallsize;
    /* 最大堆的元素个数 - 需要减去待删除的元素 */
    int largesize;
    /* 滑动窗口大小 */
    int winsize;

    /* 不断弹出heap的栈顶元素，并更新哈希表 */
    template<typename T>
    void prune(T &heap) {
        while (!heap.empty()) {
            int num = heap.top();
            if (delayed.count(num)) {
                delayed[num]--;
                if (delayed[num] == 0)
                    delayed.erase(num);
                heap.pop();
            } else {
                break;
            }
        }
    }

    /* 调整small和large有效元素个数使他们平衡 */
    void makebalance() {
        if (smallsize > largesize + 1) {
            /* small比large元素多2个 */
            large.push(small.top());
            small.pop();
            largesize++;
            smallsize--;
            /* small栈顶元素移出，需要prune */
            prune(small);
        } else if (smallsize < largesize) {
            /* small比large元素少1个 */
            small.push(large.top());
            large.pop();
            smallsize++;
            largesize--;
            /* large栈顶元素移出，需要prune */
            prune(large);
        }
    }

public:
    DualHeap(int k) : winsize(k), smallsize(0), largesize(0) {}

    void insert(int num) {
        if (small.empty() || num <= small.top()) {
            small.push(num);
            smallsize++;
        } else {
            large.push(num);
            largesize++;
        }
        makebalance();
    }

    void erase(int num) {
        delayed[num]++;
        if (num <= small.top()) {
            smallsize--;
            if (num == small.top())
                prune(small);
        } else {
            largesize--;
            if (num == large.top())
                prune(large);
        }
        makebalance();
    }

    double getmedium() {
        return winsize % 2 ? small.top() : ((double)small.top() + large.top()) * 0.5;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        /*
         * 双优先队列 + 延迟删除
         * 题目要求
         * 初始化时，将数组的前k个元素放入一个滑动窗口，并求中位数
         * 随后滑动窗口向右移动，每一次移动后，移入一个新元素，移出一个旧元素，求中位数
         * 维护一个最大堆small(一般较小元素)和一个最小堆large(一半较大元素)
         * small中元素个数和large中元素个数相等或恰好多一
         * 相等时，结果为两个堆顶平均值，不等时，结果为small的堆顶元素
         * 插入
         *      比较num和small的栈顶元素，如果num小于等于,加入small中，否则加入large中
         *      插入之后可能破坏平衡性
         *          small个数比large个数多了2个 - small栈顶放入large
         *          small个数比large个数少了1个 - large栈顶放入small
         * 删除
         *      优先队列不支持移出非栈顶元素，可以把要删除的元素记录下来，当待删除元素出现在栈顶时再删除
         * 定义两个辅助函数prune和makebalance
         * prune - 不断弹出堆中需要被删除的栈顶元素
         * makebalance - 调整small和large元素个数，使其平衡
         */
        DualHeap dh(k);
        for (int i = 0; i < k; i++) {
            dh.insert(nums[i]);
        }
        vector<double> res = {dh.getmedium()};
        for (int i = k; i < nums.size(); i++) {
            dh.insert(nums[i]);
            dh.erase(nums[i - k]);
            res.push_back(dh.getmedium());
        }

        return res;
    }
};
