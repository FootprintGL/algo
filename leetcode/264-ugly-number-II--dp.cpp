
class Solution {
public:
    int nthUglyNumber(int n) {

        /*
         * 动态规划
         * 丑数是可以被2, 3, 5整除的数
         * dp[l] = min{dp[i] * 2, dp[j] * 3, dp[k] * 5}, i, j, k -> 2,3,5对应的乘积因子
         */
        vector<int> dp(n, 0);
        int i = 0, j = 0, k = 0;
        int cur;
        dp[0] = 1;

        for (int l = 1; l < n; l++) {
            dp[l] = min(min(dp[i] * 2, dp[j] * 3), dp[k] * 5);
            if (dp[l] == dp[i] * 2)
                i++;
            if (dp[l] == dp[j] * 3)
                j++;
            if (dp[l] == dp[k] * 5)
                k++;
        }

        return dp[n - 1];
    }
};


#include <functional>

class mycomparision {
    bool reverse;
public:
    mycomparision(const bool &rev = false) {
        reverse = rev;
    }
    bool cmp(const int &lhs, const int &rhs) const {
        if (reverse)
            return lhs > rhs;
        else
            return lhs < rhs;
    }
};

class Solution {
public:
    int nthUglyNumber(int n) {
        /*
         * 最小堆
         * 每次弹出最小值i，把i * 2, i * 3, i * 5, 放入最小堆中
         * 用哈希表记录i * 2, i * 3, i * 5来避免重复项
         * 用long long类型防止整数一出
         */
        int fac[3] = {2, 3, 5};
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>>qu;
        unordered_set<long long> tbl;
        vector<long long> dp(n, 0);
        int i, j;
        long long cur;
        dp[0] = 1;

        if (n <= 0)
            return false;

        qu.push(1);
        tbl.insert(1);
        for (int i = 0; i < n; i++) {
            cur = qu.top();
            qu.pop();
            for (j = 0; j < 3; j++) {
                if (tbl.count(cur * fac[j]) == 0) {
                    qu.push(cur * fac[j]);
                    tbl.insert(cur * fac[j]);
                }
            }
            dp[i] = cur;
        }

        return dp[n - 1];
    }
};
