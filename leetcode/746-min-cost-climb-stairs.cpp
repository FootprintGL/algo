class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int> res(len, 0);
        int i;

        res[0] = cost[0];
        res[1] = cost[1];

         /* 
          * 动态规划
          * 第i层可以是从第i-2层跨2个阶梯或者从第i-1层跨1层到达
          */
        for (i = 2; i < len; i++) {
            res[i] = min(res[i - 2], res[i - 1]) + cost[i];
        }

        return min(res[len - 1], res[len - 2]);
    }
};

/* 空间优化 */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        int res, cost1, cost2;
        int i;

        cost1 = cost[0];
        cost2 = cost[1];

         /* 
          * 动态规划
          * 第i层可以是从第i-2层跨2个阶梯或者从第i-1层跨1层到达
          */
        for (i = 2; i < len; i++) {
            res = min(cost1, cost2) + cost[i];
            cost1 = cost2;
            cost2 = res;
        }

        return min(cost1, cost2);
    }
};
