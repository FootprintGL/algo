
class Solution {
public:
    bool canWinNim(int n) {
        /*
         * 脑筋急转弯
         * 3块石头肯定能赢，4块石头肯定输
         * 5-7块肯定赢，可以给对方剩下4块
         * 8块肯定输，不管拿几个，对方都可以给你留下4个
         * 9-11肯定赢，可以给对方留8个
         * 12肯定输，不管拿多少，对方都能让你剩下8个
         * 4的倍数会输，其他能赢
         */
        return n % 4 != 0;
    }
};

/* 动态规划 - 超时 */
class Solution {
public:
    bool canWinNim(int n) {
        if (n <= 3)
            return true;

        /*
         * 动态规划
         * dp[i] - i块石头玩家能不能赢
         * dp[i] = !dp[i - 1] || !dp[i - 2] || !dp[i - 3]
         * 只要有一种方案让对方输，则能赢
         * dp[1] = dp[2] = dp[3] = true
         * 结果为dp[n]
         */
        vector<bool> dp(n + 1, false);
        dp[1] = dp[2] = dp[3] = true;

        for (int i = 4; i <= n; i++) {
            if (!dp[i - 1] || !dp[i - 2] || !dp[i - 3])
                dp[i] = true;
        }

        return dp[n];
    }
};

/* 暴力递归搜索 - 超时 */
class Solution {
public:
    bool canWinNim(int n) {
        if (n <= 3)
            return true;

        /* 有一种方案能让对方输，则能赢 */
        if (!canWinNim(n - 1) || !canWinNim(n - 2) || !canWinNim(n - 3))
            return true;

        return false;
    }
};
