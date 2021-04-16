

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        /*
         * 动态规划 + 最小堆
         * 每次弹出最小值i，把i*primes[]放入最小堆
         * 用哈希表记录i*primes[]避免重复
         * long防止整数溢出
         */
        priority_queue<long, vector<long>, std::greater<long>> pq;
        unordered_set<long> tbl;
        vector<long> dp(n, 0);

        pq.push(1);
        tbl.insert(1);
        for (int i = 0; i < n; i++) {
            long cur = pq.top();
            pq.pop();
            for (int j = 0; j < primes.size(); j++) {
                long tmp = cur * primes[j];
                if (tbl.count(tmp) == 0) {
                    pq.push(tmp);
                    tbl.insert(tmp);
                }
            }
            dp[i] = cur;
        }

        return dp[n - 1];
    }
};
