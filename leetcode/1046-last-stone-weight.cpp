
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if (n == 1)
            return stones[0];

        /* priority_queue排序，每次拿最大的2个想碰，如果有剩余放回pq, 只剩最后一块或全部敲碎 */
        priority_queue<int> pq;
        int s1, s2;

        for (auto stone : stones)
            pq.push(stone);

        while (pq.size() >= 2) {
            s1 = pq.top();
            pq.pop();
            s2 = pq.top();
            pq.pop();
            if (s1 != s2)
                pq.push(abs(s1 - s2));
        }

        return pq.empty() ? 0 : pq.top();
    }
};
