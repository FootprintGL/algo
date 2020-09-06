

bool compare(string s1, string s2) {
    return s1.length() < s2.length();
}

class Solution {
public:
    /* 检查s1能否通过s2去掉一个字符转换而来 */
    bool check(string s1, string s2) {
        if (s1.length() != s2.length() + 1)
            return false;

        int i = 0, j = 0;
        while (i <= s1.length() && j < s2.length()) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }

        return j == s2.length();
    }



    int longestStrChain(vector<string>& words) {
        /*
         * 动态规划
         * 先按长度排序
         * dp[i] - 以words[i]为结尾的最大词链长度
         * dp[i] = max{dp[i], dp[j] + 1}, string-j可以通过string-i删除一个字符转换而来
         */
        sort(words.begin(), words.end(), compare);
        int n = words.size(), ans = 1;
        vector<int> dp(n, 1);
        int i, j;

        for (i = 1; i < n; i++) {
            for (j = i - 1; j >= 0; j--) {
                if (words[i].length() == words[j].length()) {
                    continue;
                } else if (words[i].length() == words[j].length() + 1) {
                    if (check(words[i], words[j])) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                } else {
                    /* 长度相差等于2，从j开始往前长度都相差大于等于2，停止出来 */
                    break;
                }
            }
            ans = max(ans, dp[i]);
        }
/*
        for (i = 0; i < n; i++)
            cout << dp[i] << " ";
        cout << endl;
*/
        return ans;
    }
};
