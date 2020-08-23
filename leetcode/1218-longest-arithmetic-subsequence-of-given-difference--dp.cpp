

/* 哈希表优化 */
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        /*
         * 动态规划
         * dp[i] - 表示以arr[i]结尾的最长等差子序列长度
         * dp[i] = max{dp[j] + 1}, j: 0 -> i, 如果arr[i] - arr[i - j] == difference
         * dp[0] = 1
         * 边计算边更新结果ans
         * 超时了
         *****************************************************************
         * 用map<arr[i], len>维护以arr[i]结尾的最长等差子序列长度
         * 如果i - difference在map里，dp[i] = dp[i - difference] + 1
         * 如果i - difference不在map里，dp[i] = 1
         */
        int n = arr.size();
        unordered_map<int, int> map;
        int ans;
        int i;

        ans = 1;
        for (auto i : arr) {
            if (map.find(i - difference) == map.end()) {
                /* i - difference没出现过 */
                map[i] = 1;
            } else {
                /* i - difference出现过 */
                map[i] = map[i - difference] + 1;
            }
            if (ans < map[i])
                ans = map[i];
            //cout << i << " " << map[i] << endl;
        }

        return ans;
    }
};

/* 超出时间限制 */
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        /*
         * 动态规划
         * dp[i] - 表示以arr[i]结尾的最长等差子序列长度
         * dp[i] = max{dp[j] + 1}, j: 0 -> i, 如果arr[i] - arr[i - j] == difference
         * dp[0] = 1
         * 边计算边更新结果ans
         */
        int n = arr.size();
        vector<int> dp(n, 0);
        int ans;
        int i, j;

        ans = dp[0] = 1;
        for (i = 1; i < n; i++) {
            dp[i] = 1;
            for (j = 0; j < i; j++) {
                if (arr[i] - arr[j] == difference) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (ans < dp[i])
                ans = dp[i];
        }

        return ans;
    }
};
