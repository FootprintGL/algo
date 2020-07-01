class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> map(wordDict.begin(), wordDict.end());
        int len = s.size();
        vector<bool> dp(len + 1, false);
        int i, j;

        /*
         * 动态规划
         * dp[0] = true
         * dp[i] - j为分割[0 ～ i-1]字串，如果[j, i-1]的字串在字典里并且dp[j]可以拆分
         * 则dp[i]也可以拆分，j从0 -> i - 1, 最后返回dp[len]
         */
        dp[0] = true;
        for (i = 1; i < len + 1; i++) {
            for (j = 0; j < i; j++) {
                if (map.find(s.substr(j, i - j)) != map.end() && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[len];
    }
};
