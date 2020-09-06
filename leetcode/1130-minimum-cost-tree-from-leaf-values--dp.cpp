


class Solution {
public:
    void dump(vector<vector<int>> & arr) {
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr[0].size(); j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }

    int mctFromLeafValues(vector<int>& arr) {
        /*
         * 动态规划
         * dp[i][j] - i -> j生成树的和的最小值
         * dp[i][j] = dp[i][k] + dp[k + 1][j] + max{arr: i -> k} * max{arr: k + 1 -> j}, k = i -> j
         * dp[i][i] = 0, dp[i][i + 1] = arr[i] * arr[i + 1]
         * 结果为dp[0][n - 1]
         */
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        vector<vector<int>> maxvalue(n, vector<int> (n, 0));
        int i, j, k, len;

        /* 计算i -> j的最大值 */
        for (i = 0; i < n; i++) {
            for (j = i; j <n; j++) {
                int tmp = 0;
                for (k = i; k <= j; k++) {
                    if (arr[k] > tmp)
                        tmp = arr[k];
                }
                maxvalue[i][j] = tmp;
            }
        }

        //dump(maxvalue);
        //cout << endl;

        for (i = 0; i < n; i++) {
            dp[i][i] = 0;
        }

        for (i = 0; i < n - 1; i++)
            dp[i][i + 1] = arr[i] * arr[i + 1];

        for (len = 3; len <= n; len++) {
            for (i = n - len; i >= 0; i--) {
                for (j = i + len - 1; j < n; j++) {
                    for (k = i; k < j; k++) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + maxvalue[i][k] * maxvalue[k + 1][j]);
                    }
                }
            }
        }

        //dump(dp);

        return dp[0][n - 1];
    }
};

/* 
 * 该解法是错的，不具有无后效性，后面的选择会影响前面的结果
 * arr[i]和arr[i-1]组合时，前面的结果可能是arr[i-1]和arr[i-2]组合的 */
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        /*
         * 动态规划
         * dp[i] - 前i个数字构成的有效二叉树中非叶节点的最小总和
         *      1. arr[i] 可以单独作为右子树 dp[i] = dp[i - 1] + arr[i] * max{arr[0] ~ arr[i - 1]}
         *      2. arr[i]和arr[i - 1]组合一起成右子树 dp[i] = dp[i - 2] + arr[i] * arr[i - 1] + max(arr[i], arr[i - 1]) * max{arr[0] ~ arr[i - 2]}
         * dp[i]取其中小的
         * dp[0] = 0, dp[1] = arr[0] * arr[1]
         * 结果为dp[n - 1]
         */
        int n = arr.size();
        vector<int> dp(n, INT_MAX);
        vector<int> maximum(n, 0);
        int maxvalue = 0, i;

        /* 计算0 -> i的最大值 */
        for (i = 0; i < n; i++) {
            if (arr[i] > maxvalue)
                maxvalue = arr[i];
            maximum[i] = maxvalue;
        }

        dp[0] = 0;
        dp[1] = arr[0] * arr[1];
        for (i = 2; i < n; i++) {
            dp[i] = min(dp[i - 1] + arr[i] * maximum[i - 1], dp[i - 2] + maximum[i - 2] * max(arr[i], arr[i - 1]) + arr[i] * arr[i - 1]);
        }

        for (i = 0; i < n; i++)
            cout << dp[i] << " ";
        cout << endl;

        for (i = 0; i < n; i++)
            cout << maximum[i] << " ";
        cout << endl;

        return dp[n - 1];
    }
};
