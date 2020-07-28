/* 动态规划 - 窗口变量 - 记忆化递归DFS算法 */
class Solution {
public:
    vector<int> days, costs;
    vector<int> memo;
    int dur[3] = {1, 7, 30};

    /*
     * 动态规划 - 记忆化递归DFS算法
     * dp[i] - 表示从days[i]天到年底需要的最小费用
     * j1表示满足days[j1] >= day[i] + 1的最小下表
     * j7表示满足days[j7] >= day[i] + 7的最小下表
     * j30表示满足days[j30] >= day[i] + 30的最小下表
     * dp[i] = min(dp[j1] + costs[0], dp[j7] + costs[1], dp[j30] + costs[j30])
     * dp[0]即为结果
     */
    int dfs(int i) {
        if (i > days.size() - 1)
            return 0;

        if (memo[i] != -1)
            return memo[i];

        memo[i] = INT_MAX;
        int j = i;
        for (int k = 0; k < 3; k++) {
            while (j < days.size() && days[j] < days[i] + dur[k])
                j++;
            memo[i] = min(memo[i], dfs(j) + costs[k]);
        }

        return memo[i];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->days = days;
        this->costs = costs;
        memo.assign(days.size(), -1);

        return dfs(0);
    }
};


/* 动态规划 - 日期 - 递归 */
class Solution {
public:

    /* 动态规划 - 记忆化递归DFS算法 */
    int dfs(int day, vector<int> &memo, unordered_set<int> &dataset, vector<int> &costs) {
        if (day > 365)
            return 0;

        if (memo[day] != 0)
            return memo[day];
        
        if (dataset.count(day)) {
            memo[day] = dfs(day + 1, memo, dataset, costs) + costs[0];
            memo[day] = min(memo[day], dfs(day + 7, memo, dataset, costs) + costs[1]);
            memo[day] = min(memo[day], dfs(day + 30, memo, dataset, costs) + costs[2]);
        } else {
            memo[day] = dfs(day + 1, memo, dataset, costs);
        }
    
        return memo[day];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> memo(366);
        unordered_set<int> dataset;

        for (auto day : days)
            dataset.insert(day);

        return dfs(1, memo, dataset, costs);
    }
};



class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int len = days.size();
        vector<int> dp(396, 0);
        int i, j;
        /*
         * 动态规划 - 从后往前
         * dp[i] - 第i天到年底需要的最小花费
         * dp[i] = min(dp[i + 1] + costs[0], dp[i + 7] + costs[1], dp[i + 30] + cost[2])
         * if i > days[len - 1], dp[i] = 0
         * 如果i天没有旅游机会的话，dp[i] = dp[i + 1]
         * 结果为dp[days[0] - 1]
         */
        i = len - 1;
        j = days[i] - 1;
        dp[j] = dp[j + 1] + costs[0];
        dp[j] = min(dp[j], dp[j + 7] + costs[1]);
        dp[j] = min(dp[j], dp[j + 30] + costs[2]);
        
        //cout << i << "   " << j - 1 << " " << dp[j] << endl;\
        j--;
        while (i >= 0 && j >= 0) {
            /* 如果第i天没有旅行计划dp[j] = dp[j + 1] */
            while(i - 1 >= 0 && j > days[i - 1] - 1) {
                dp[j] = dp[days[i] - 1];
                cout << i << " -  " << j << " " << dp[j] << endl;
                j--;
            }
            /* 找到下一个需要旅游的时间第j天 */
            if (i >= 0) {
                dp[j] = dp[j + 1] + costs[0];
                dp[j] = min(dp[j], dp[j + 7] + costs[1]);
                dp[j] = min(dp[j], dp[j + 30] + costs[2]);
                //cout << i << " -- " << j << " " << dp[j] << endl;
                i--;
                j--;
            }
        }

        return dp[days[0] - 1];
    }
};


/* 下面的测试case会fail: days = [1,4,6,7,8,20] costs = [7,2,15], 一天票价竟然比一周还贵 */
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int len = days.size();
        vector<int> dp(396, 0);
        int i, j;
        /*
         * 动态规划 - 从后往前
         * dp[i] - 第i天到年底需要的最小花费
         * dp[i] = min(dp[i + 1] + costs[0], dp[i + 7] + costs[1], dp[i + 30] + cost[2])
         * if i > days[len - 1], dp[i] = 0
         * 如果i天没有旅游机会的话，dp[i] = dp[i + 1]
         * 结果为dp[days[0] - 1]
         */
        i = len - 1;
        dp[days[i] - 1] = dp[days[i]] + costs[0];
        j = days[i] - 2;
        cout << i << "   " << days[i] - 1 << " " << dp[days[i] - 1] << endl;
        while (i >= 0 && j >= 0) {
            /* 如果第i天没有旅行计划dp[j] = dp[j + 1] */
            while(i - 1 >= 0 && j > days[i - 1] - 1) {
                dp[j] = dp[days[i] - 1];
                cout << i << " -  " << j << " " << dp[j] << endl;
                j--;
            }
            /* 找到下一个需要旅游的时间第j天 */
            if (i >= 0) {
                dp[j] = dp[j + 1] + costs[0];
                if (j + 7 <= 365 && dp[j + 7] + costs[1] < dp[j])
                    dp[j] = dp[j + 7] + costs[1];
                if (j + 30 <= 365 && dp[j + 30] + costs[2] < dp[j])
                    dp[j] = dp[j + 30] + costs[2];
                cout << i << " -- " << j << " " << dp[j] << endl;
                i--;
                j--;
            }
        }

        cout << dp[0] << " " << days[0] << " " << dp[days[0] - 1] << endl;

        return dp[days[0] - 1];
    }
};
