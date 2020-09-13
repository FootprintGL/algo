class Solution {
public:
    static bool cmp(pair<int, int> &m, pair<int, int> &n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> tbl;

        for (auto num : nums)
            tbl[num]++;

        //priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pq(cmp);
        priority_queue<pair<int, int>> pq;
        for (auto &[num, count] : tbl)
            pq.emplace(count, num);

        while (!pq.empty() && k-- > 0) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};


class Solution {
public:
    static bool cmp(pair<int, int> &m, pair<int, int> &n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> tbl;

        for (auto num : nums)
            tbl[num]++;

        //priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        priority_queue<pair<int, int>> pq;
        for (auto &[num, count] : tbl) {
            /*
            if (pq.size() == k) {
                if (pq.top().second < count) {
                    pq.pop();
                    pq.emplace(num, count);
                }
            } else {
                pq.emplace(num, count);
            }
            */
            pq.emplace(count, num);
            //cout << count << " " << num << endl;
        }
        cout << endl;

        while (!pq.empty() && k-- > 0) {
            res.push_back(pq.top().second);
            //cout << pq.top().first << " " << pq.top().second << endl;
            pq.pop();
        }

        return res;
    }
};

class Solution {
public:
    static bool cmp(pair<int, int> &m, pair<int, int> &n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> tbl;

        for (auto num : nums)
            tbl[num]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pq(cmp);
        for (auto &[num, count] : tbl) {
            if (pq.size() == k) {
                if (pq.top().second < count) {
                    pq.pop();
                    pq.emplace(num, count);
                }
            } else {
                pq.emplace(num, count);
            }
        }

        while (!pq.empty()) {
            res.insert(res.begin(), pq.top().first);
            pq.pop();
        }

        return res;
    }
};

