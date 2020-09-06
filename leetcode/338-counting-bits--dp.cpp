

class Solution {
public:
    vector<int> countBits(int num) {
        /* 动态规划 dp[i] = dp[i & (i - 1)] + 1 */
        vector<int> dp(num + 1, 0);
        for (int i = 1; i <= num; i++)
            dp[i] = dp[i & (i - 1)] + 1;
        return dp;
    }
};

class Solution {
public:
    vector<int> countBits(int num) {
        /* 动态规划 dp[i] = dp[i / 2] + i % 2 */
        vector<int> dp(num + 1, 0);
        for (int i = 1; i <= num; i++)
            dp[i] = dp[i / 2] + i % 2;
        return dp;
    }
};

class Solution {
public:
    /* 统计n中1的个数 */
    int bitscnt(int n) {
        int cnt = 0;
        while (n) {
            n &= n - 1;
            cnt++;
        }
        return cnt;
    }

    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for (int i = 0; i <= num; i++) {
            res[i] = bitscnt(i);
        }
        return res;
    }
};
