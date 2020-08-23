
class Solution {
public:
    /* 排序比较函数 */
    static bool mycompare(vector<int> p1, vector<int> p2) {
        return p1[1] < p2[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {

        /* 将pair以第一个数由小到大排序 */
        sort(pairs.begin(), pairs.end(), mycompare);

        /*
         * 贪心算法
         * pairs以第二个数排序, 从pairs[0]开始向右
         * 如果pairs[i][0] > pairs[j][1], 更新ans++
         */
        int ans = 1;
        int n = pairs.size();
        int i, j = 0;

        for (i = 1; i < n; i++) {
            if (pairs[i][0] > pairs[j][1]) {
                j = i;
                ans++;
            }
        }

        return ans;
    }
};


class Solution {
public:
    /* 排序比较函数 */
    static bool mycompare(vector<int> p1, vector<int> p2) {
        return p1[0] < p2[0];
    }

    int findLongestChain(vector<vector<int>>& pairs) {

        /* 将pair以第一个数由小到大排序 */
        sort(pairs.begin(), pairs.end(), mycompare);

        /*
         * 动态规划
         * dp[i] = 以pairs[i]结尾的最长数对链的长度
         * dp[i] = dp[j] + 1, j: 0 -> i - 1 && pairs[j] < pairs[i]
         * 边计算边更新最大长度
         */
        int ans = 1;
        int n = pairs.size();
        vector<int> dp(n, 1);
        int i, j;

        for (i = 1; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = dp[j] + 1;
                    if (ans < dp[i])
                        ans = dp[i];
                }
            }
        }

        return ans;
    }
};
