class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        /*
         * 动态规划
         * dp[i][j] - 前i个元素和模3余j的最大和，j = 0, 1, 2
         * 每个元素可选可不选
         * dp[i][0] = max{dp[i - 1][0], dp[i - 1][(3 + 0 - nums[i] % 3) % 3] + nums[i]}
         * dp[i][1] = max{dp[i - 1][1], dp[i - 1][(3 + 1 - nums[i] % 3) % 3] + nums[i}
         * dp[i][2] = max{dp[i - 1][1], dp[i - 1][(3 + 2 - nums[i] % 3) % 3] + nums[i}
         * dp[i][j] = max{dp[i - 1][j], dp[i - 1][(3 + j - nums[i] % 3) % 3] + nums[i]}
         * 多加1行方便处理dp[0][0] = 0, dp[0][1] = dp[0][2] = INT_MIN (因为是求最大值)
         * 结果为dp[n][0]
         * 每一行结果之和上一行有关，可以进行状态压缩
         */
        int m = nums.size();
        vector<int>dp(3, 0);
        vector<int>tmp(3, 0);
        int mod, i;

        for (i = 0; i < m; i++) {
            mod = nums[i] % 3;
            tmp[0] = dp[(3 + 0 - mod) % 3];
            tmp[1] = dp[(3 + 1 - mod) % 3];
            tmp[2] = dp[(3 + 2 - mod) % 3];

            if (tmp[0] || mod == 0)
                dp[0] = max(dp[0], tmp[0] + nums[i]);
            if (tmp[1] || mod == 1)
                dp[1] = max(dp[1], tmp[1] + nums[i]);
            if (tmp[2] || mod == 2)
                dp[2] = max(dp[2], tmp[2] + nums[i]);
            //cout << dp[0] << " " << dp[1] << " " << dp[2] << endl;
        }
/*
        for (i = 0; i <= m; i++) {
            for (j = 0; j < n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
*/
        return dp[0];
    }
};





class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        /*
         * 动态规划
         * dp[i][j] - 前i个元素和模3余j的最大和，j = 0, 1, 2
         * 每个元素可选可不选
         * dp[i][0] = max{dp[i - 1][0], dp[i - 1][(3 + 0 - nums[i] % 3) % 3] + nums[i]}
         * dp[i][1] = max{dp[i - 1][1], dp[i - 1][(3 + 1 - nums[i] % 3) % 3] + nums[i}
         * dp[i][2] = max{dp[i - 1][1], dp[i - 1][(3 + 2 - nums[i] % 3) % 3] + nums[i}
         * dp[i][j] = max{dp[i - 1][j], dp[i - 1][(3 + j - nums[i] % 3) % 3] + nums[i]}
         * 多加1行方便处理dp[0][0] = 0, dp[0][1] = dp[0][2] = INT_MIN (因为是求最大值)
         * 结果为dp[n][0]
         * 每一行结果之和上一行有关，可以进行状态压缩
         */
        int m = nums.size();
        vector<int>dp(3, 0);
        vector<int>tmp(3, 0);
        int a, b, c, mod, i;
        dp[1] = dp[2] = INT_MIN;

        for (i = 0; i < m; i++) {
            mod = nums[i] % 3;
            tmp = dp;

            if (mod == 0) {
                dp[0] = max(dp[0], tmp[0] + nums[i]);
                dp[1] = max(dp[1], tmp[1] + nums[i]);
                dp[2] = max(dp[2], tmp[2] + nums[i]);
            } else if (mod == 1) {
                dp[0] = max(dp[0], tmp[2] + nums[i]);
                dp[1] = max(dp[1], tmp[0] + nums[i]);
                dp[2] = max(dp[2], tmp[1] + nums[i]);
            } else {
                dp[0] = max(dp[0], tmp[1] + nums[i]);
                dp[1] = max(dp[1], tmp[2] + nums[i]);
                dp[2] = max(dp[2], tmp[0] + nums[i]);
            }
        }
/*
        for (i = 0; i <= m; i++) {
            for (j = 0; j < n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
*/
        return dp[0];
    }
};




class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        /*
         * 动态规划
         * dp[i][j] - 前i个元素和模3余j的最大和，j = 0, 1, 2
         * 每个元素可选可不选
         * dp[i][0] = max{dp[i - 1][0], dp[i - 1][(3 + 0 - nums[i] % 3) % 3] + nums[i]}
         * dp[i][1] = max{dp[i - 1][1], dp[i - 1][(3 + 1 - nums[i] % 3) % 3] + nums[i}
         * dp[i][2] = max{dp[i - 1][1], dp[i - 1][(3 + 2 - nums[i] % 3) % 3] + nums[i}
         * dp[i][j] = max{dp[i - 1][j], dp[i - 1][(3 + j - nums[i] % 3) % 3] + nums[i]}
         * 多加1行方便处理dp[0][0] = 0, dp[0][1] = dp[0][2] = INT_MIN (因为是求最大值)
         * 结果为dp[n][0]
         */
        int m = nums.size();
        int n = 3;
        vector<vector<int>> dp(m + 1, vector<int>(3, 0));
        int i, j;

        dp[0][1] = dp[0][2] = INT_MIN;
        for (i = 1; i <= m; i++) {
            for (j = 0; j < n; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][(3 + j - nums[i - 1] % 3) % 3] + nums[i - 1]);
            }
        }
/*
        for (i = 0; i <= m; i++) {
            for (j = 0; j < n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
*/
        return dp[m][0];
    }
};
