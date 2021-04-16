

class Solution {
public:
    bool comp(vector<int> &a, vector<int> &b) {
        return a[0] - a[1] < b[0] - b[1];
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        /*
         * 贪心
         * 2N个人安排飞往B，再选N个人飞往A，公司将额外支付A - B的费用
         * 选出priceA - priceB最小的N个人飞往A，其余人飞往B
         */
        int res = 0;
        int n = costs.size();

        /* 按priceA - priceB排序 */
        sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] - a[1] < b[0] - b[1];
        });

        /* 前N个飞到A后N个飞到B的费用 */
        for (int i = 0; i < n / 2; i++)
            res += costs[i][0] + costs[n / 2 + i][1];

        return res;
    }
};
