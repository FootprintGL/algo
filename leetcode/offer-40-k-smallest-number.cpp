

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, std::greater<int>> pq(arr.begin(), arr.end());
        vector<int> res;

        /* 优先队列 */
        while (k) {
            res.push_back(pq.top());
            pq.pop();
            k--;
        }

        return res;
    }
};
