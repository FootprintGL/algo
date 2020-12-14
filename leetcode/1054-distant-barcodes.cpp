
using Pair = pair<int, int>;
bool cmp(Pair &p1, Pair &p2) {
    return p1.second > p2.second;
}

struct Cmp{
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;
    }
};

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        /* 优先放剩下最多和第二多的数字 */
        vector<int> res;
        priority_queue<Pair, vector<Pair>, Cmp> pq;
        unordered_map<int, int> cnt;
        int n = barcodes.size();

        /* 哈希表统计每个数字出现的次数 */
        for (auto &b : barcodes)
            cnt[b]++;

        /* {num, cnt}放入优先队列，按cnt从大到小排序 */
        for (auto &p : cnt)
            pq.push({p.first, p.second});

        while (!pq.empty()) {
            /* 取剩下最多的元素 */
            Pair cur = pq.top();
            pq.pop();

            if (!res.empty() && cur.first == res.back()) {
                /* 当前最多的刚放过，放下一个多的 */
                Pair next = pq.top();
                pq.pop();
                res.push_back(next.first);
                next.second--;
                if (next.second)
                    pq.push(next);
            } else {
                res.push_back(cur.first);
                cur.second--;
            }
            if (cur.second)
                pq.push(cur);
        }

        return res;
    }
};
