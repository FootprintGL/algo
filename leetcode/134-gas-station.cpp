
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        /*
         * 贪心
         * 如果总油量减去总消耗大于0，则一定可以跑完一圈，说明各个站点的加油站
         * 剩油量remain[i]相加一定是大于0的
         * remain[i] = gas[i] - cost[i]
         * i从0开始累加remain[i], cursum, 如果cursum < 0, 说明[0,i]区间不能作为起始位置
         * 起始位置从i + 1开始
         * 为什么[i, j]区间和为负数，起始位置从j + 1呢？
         * j之前出现过多少负数，j后面就会出现多少正数，因为剩余综合是大于0的
         * 前提是我们一定能跑完全程 sum(remain[i]) > 0
         */
        int cursum = 0, totalsum = 0, start = 0;

        for (int i = 0; i < gas.size(); i++) {
            cursum += gas[i] - cost[i];
            totalsum += gas[i] - cost[i];
            if (cursum < 0) {
                start = i + 1;
                cursum = 0;
            }
        }

        if (totalsum < 0)
            return -1;
        
        return start;
    }
};



/* 暴力 - 逐个检查 */
class Solution {
public:
    bool helper(vector<int> &gas, vector<int> &cost, int n, int start, int &cur) {
        /* 检查从start开始能否走完一圈 */
        int i = start;

        while (i < n) {
            cur += gas[i];
            //cout << i << " " << gas[i] << " " << cost[i] << " " << cur << endl;
            if (cur < cost[i]) {
                //cout << endl;
                return false;
            }
            cur -= cost[i];

            i++;
            i %= n;
            if (i == start)
                break;
        }
        //cout << endl;

        return true;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int m = gas.size(), n = cost.size();
        int cur = 0;

        if (n == 0 || m != n)
            return -1;

        for (int i = 0; i < n; i++) {
            cur = 0;
            //cout << i << " " << cur << " " << n << endl;
            if (helper(gas, cost, n, i, cur))
                return i;
        }

        return -1;
    }
};
