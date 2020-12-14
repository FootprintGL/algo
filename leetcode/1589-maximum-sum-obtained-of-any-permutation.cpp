
/* 差分数组计算区间频率 */
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        /*
         * 贪心 - 出现频率高的index放大的数字
         * 差分数组cnt[i]++, 求前缀和还原时，相当于[i, n]区间每个下标的出现次数+1
         * 计算区间[i,j]，为了抵消cnt[i]++对[j + 1, n]的影响，可以cnt[j + 1]--
         * 这样就可以算出[i, j]出现的次数了
         */
        const int M = 1e9 + 7;
        int n = nums.size();
        vector<int> cnt(n, 0);

        /* 计算每个位置出现的次数 */
        for (auto &req : requests) {
            cnt[req[0]]++;
            if (req[1] + 1 < n)
                cnt[req[1] + 1]--;
        }

        /* 求前缀和 */
        for (int i = 1; i < n; i++)
            cnt[i] += cnt[i - 1];

        /* 计算结果 */
        long res = 0; //long防止溢出
        sort(nums.begin(), nums.end());
        sort(cnt.begin(), cnt.end());
        for (int i = 0; i < n; i++) {
            res = (res + (long)nums[i] * cnt[i]) % M;
        }

        return res;
    }
};



/* 超时 */
using Pair = pair<int, int>;

struct cmp {
    bool operator()(Pair &a, Pair &b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        /* 贪心 - 重叠区域（高频位置）放较大的数 */
        int n = nums.size();
        int M = 1e9 + 7;
        vector<int> tmp(n, 0);
        vector<int> freq(n, 0);

        /* 统计每个index出现的次数 */
        for (auto &req : requests)
            for (int i = req[0]; i <= req[1]; i++)
                freq[i]++;

        /* 大顶堆 - 按出现次数排序 */
        priority_queue<Pair, vector<Pair>, cmp> pq;
        for (int i = 0; i < n; i++)
            if (freq[i])
                pq.push({i, freq[i]});

        /* nums递减排序 */
        sort(nums.begin(), nums.end(), std::greater());

        /* index出现频率大的放大数 */
        int p = 0;
        while (!pq.empty()) {
            Pair cur = pq.top();
            pq.pop();
            tmp[cur.first] = nums[p++];
        }

        /* 计算前缀和 */
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + tmp[i - 1];

        /* 计算结果 */
        long res = 0;
        for (auto &req : requests) {
            res += sum[req[1] + 1] - sum[req[0]];
            res %= M;
        }

        return res;
    }
};
