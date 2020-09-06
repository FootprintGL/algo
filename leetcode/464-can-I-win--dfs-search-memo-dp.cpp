

class Solution {
public:
    bool dfs(int maxChoosableInteger, int desiredTotal, int state, vector<int> &dp) {
        //cout << setbase(10) << maxChoosableInteger << " " << desiredTotal << " " << setbase(16) << state << endl;
        if (dp[state] < 2)
            return dp[state] == 1 ? true : false;

        for (int i = 1; i <= maxChoosableInteger; i++) {
            int cur = 1 << (i - 1);

            if ((state & cur) != 0)
            /* i已使用，跳过 */
                continue;

            if (desiredTotal - i <= 0 ||
                dfs(maxChoosableInteger, desiredTotal - i, state | cur, dp) == false) {
                dp[state] = 1;
                return true;
            }
        }

        dp[state] = 0;
        return false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal)
            return true;

        if ((maxChoosableInteger + 1) * maxChoosableInteger / 2 < desiredTotal)
            return false;

        /*
         * 记忆化搜索
         * state二进制位标记当前剩余数字状态，1表示已使用，0表示未使用
         * dp[state]记录state下当前选手是赢还是输，len是1 << maxChoosableInteger
         * dp[state] == 0 -> 输，1 -> 赢
         * 如果A赢或存在一种选择使得B输，则A赢 - 假设两位玩家都表现最佳
         */
        vector<int> dp(1 << maxChoosableInteger, 2);

        return dfs(maxChoosableInteger, desiredTotal, 0, dp);
    }
};
