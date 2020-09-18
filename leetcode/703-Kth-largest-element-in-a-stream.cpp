
class KthLargest {
public:
    /* 优先队列 - 最小堆 */
    priority_queue<int, vector<int>, std::greater<int>> pq;
    int K;

    KthLargest(int k, vector<int>& nums) {
        for (auto num : nums) {
            pq.push(num);
            if (pq.size() > k)
                pq.pop();
        }
        K = k;
    }

    int add(int val) {
        pq.push(val);

        if (pq.size() > K)
            pq.pop();

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

/* 超时 */
class KthLargest {
public:
    priority_queue<int> pq;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto num : nums)
            pq.push(num);
    }

    int add(int val) {
        vector<int> tmp;
        pq.push(val);

        /* 出队k-1个 */
        for (int i = 0; i < k - 1; i++) {
            tmp.push_back(pq.top());
            pq.pop();
        }

        /* 头部为第k大 */
        int res = pq.top();

        /* 缓存数据放回优先队列 */
        for(auto num : tmp)
            pq.push(num);

        return res;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
