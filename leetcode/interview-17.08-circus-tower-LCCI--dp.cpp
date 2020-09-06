

class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        /*
         * 动态规划
         * 高度从小到大排序，然后寻找重量递增子序列
         * 高度相同时，按重量从大到小排列，避免递增子序列高度相同的解
         * dp[i] - 长度为i + 1的末尾元素的最小值
         * 每个weight[i], 在dp中寻找地一个小于等于的下表
         * 如果找到则替换，找不到说明weight[i]是一个新的最大元素，直接插入dp表
         * dp表一定是严格递增的，结果为dp[i]的长度
         */
        vector<pair<int, int>> tbl;
        int n = height.size();
        if (n == 0)
            return 0;
        vector<int> dp;

        for (int i = 0; i < n; i++) {
            tbl.push_back({height[i], weight[i]});
        }

        sort(tbl.begin(), tbl.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        });
/*
        for (auto t : tbl)
            cout << t.first << " " << t.second << endl;
*/
        for (auto &[h, w] : tbl) {
            auto p = lower_bound(dp.begin(), dp.end(), w);
            if (p == dp.end())
                /* w是新的大元素，插入dp，最长子序列长度+1 */
                dp.push_back(w);
            else
                /* 更新p出最小元素 */
                *p = w;
        }
        
        return dp.size();
    }
};


/* 超时 */
class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        /*
         * 动态规划
         * 高度从小到大排序，然后寻找重量递增子序列
         * 高度相同时，按重量从大到小排列，避免递增子序列高度相同的解
         * dp[i] - 以pair(height, weight)结尾的最长递增子序列长度
         * dp[i] = max(dp[j] + 1), 如果height[i] > height[j]
         * 边界条件dp[0] = 1
         * 边计算边更新结果ans
         */
        vector<pair<int, int>> tbl;
        int n = height.size();
        if (n == 0)
            return 0;
        vector<int> dp (n, 1);
        int i, j, ans = 0;

        for (i = 0; i < n; i++) {
            tbl.push_back({height[i], weight[i]});
        }

        sort(tbl.begin(), tbl.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        });

/*
        for (auto t : tbl)
            cout << t.first << " " << t.second << endl;
*/
        ans = 1;
        for (i = 1; i < n; i++) {
            for (j = 0; j < i; j++) {
                if (tbl[i].second > tbl[j].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
            //cout << dp[i] << " ";
        }
        //cout << endl;

        return ans;
    }
};
