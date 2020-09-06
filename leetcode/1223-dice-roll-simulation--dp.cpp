

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {

        /*
         * 动态规划
         * dp[i][j][k] - 第i次掷出j时已连续出现k次的情况
         * k = 1时，dp[i][j][1] = sum(d[[i - 1][others != j][:]])上一次投出非数字j的所有组合
         * k > 1时，如果k <= rollmax[j], dp[i - 1][j][k - 1]
         * dp[0][j][1] = {1,...,1}, dp[0][j][1] - 表示第一次就掷出j，有一种
         */
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(6, vector<int>(16, 0)));
        int i, j, k;
        int M = 1000000007, ans = 0;

        /* dp[0][j][1] - 表示第一次就掷出j，有一种 */
        for (j = 0; j < 6; j++) {
            dp[0][j][1] = 1;
        }

        for (i = 1; i < n; i++) {
            for (j = 0; j < 6; j++) {
                for (k = 1; k <= rollMax[j]; k++) {
                    if (k == 1) {
                        /* k == 1, 上次掷出其他数字的所有可能 */
                        ans = 0;
                        for (int l = 0; l < 6; l++) {
                            if (l != j) {
                                /* 上次掷出的是其他数字 */
                                for (int s = 1; s <= rollMax[l]; s++)
                                    ans = (ans + dp[i - 1][l][s]) % M;
                            }
                        }
                        dp[i][j][k] = ans;
                    } else {
                        /* k > 1，上一次掷出的也是j */
                        dp[i][j][k] = dp[i - 1][j][k - 1];
                    }
                }
            }
        }

/*
        for (i = 0; i < n; i++) {
            for (j = 0; j < 6; j++) {
                for (k = 1; k <= rollMax[j]; k++)
                    cout << dp[i][j][k] << " ";
                cout << endl;
            }
            cout << endl;
        }
        cout << endl;
*/
        ans = 0;
        for (j = 0; j < 6; j++) {
            for (k = 1; k <= rollMax[j]; k++) {
                ans = (ans + dp[n - 1][j][k]) % M;
            }
        }

        return ans;
    }
};
