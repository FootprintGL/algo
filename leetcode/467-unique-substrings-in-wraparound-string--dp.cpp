

class Solution {
public:
    bool continuous(char a, char b) {
        if (a == 'z')
            return b == 'a';
        return (a + 1 == b);
    }

    int findSubstringInWraproundString(string p) {
        /*
         * 动态规划
         * dp[i] - 以dp[i]为结尾的最长字串长度
         * dp[i] = dp[i - 1] + 1, 如果p[i - 1]p[i]连续
         * dp[i] = 1，如果p[i - 1]p[i]不连续
         * 结果为dp内所有元素之和
         * 去重: 长串会覆盖短串
         */
        vector<int> dp(26, 0);
        int n = p.length(), k = 0;

        for (int i = 0; i < n; i++) {
            if (i > 0 && continuous(p[i - 1], p[i]))
                k++;
            else
                k = 1;

            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
        }
/*
        for (auto a : dp)
            cout << a << " ";
        cout << endl;
*/
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
