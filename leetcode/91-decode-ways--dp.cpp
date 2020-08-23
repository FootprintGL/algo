

class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();

        /*
         * 动态规划 - 滚动数组优化
         * dp[i]从[0,i - 1]字串解码方法
         * 如果s[i - 2]s[i - 1]为有效字母，s[i - 1]可以单独解码，也可以和前一个字符组合解码
         * 即在[1,26]中dp[i] = dp[i - 1] + dp[i - 2]
         * 如果s[i - 2]s[i - 1]不是有效字母，则没有增加解码方法，dp[i] = dp[i - 1]
         * 边界条件: dp[0] = dp[1] = 1
         * 结果为dp[len]
         * 注意: 注意”0”的特殊处理，且给定的字符串存在无解情况，如"0", "30"等等
         */

        if (s[0] == '0')
            return 0;

        /* dp[-1] = dp[0] = 1 */
        int prev = 1, curr = 1;
        int tmp;
        for (int i = 1; i < len; i++) {
            tmp = curr;
            if (s[i] == '0') {
                /* 不存在前缀0，当s[i - 1]为0时，只能和s[i - 2]组合起来解码 */
                if (s[i - 1] == '1' || s[i - 1] == '2')
                    /* s[i - 2]s[i - 1]组合为有效字母 */
                    curr = prev;
                else
                    /* s[i - 2]s[i - 1]不能组合为有效字母 */
                    return 0;
            } else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                    curr += prev;
            }
            prev = tmp;
            //cout << curr << " " << prev << endl;
        }

        return curr;
    }
};


class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();

        /*
         * 动态规划
         * dp[i]从[0,i - 1]字串解码方法
         * 如果s[i - 2]s[i - 1]为有效字母，s[i - 1]可以单独解码，也可以和前一个字符组合解码
         * 即在[1,26]中dp[i] = dp[i - 1] + dp[i - 2]
         * 如果s[i - 2]s[i - 1]不是有效字母，则没有增加解码方法，dp[i] = dp[i - 1]
         * 边界条件: dp[0] = dp[1] = 1
         * 结果为dp[len]
         * 注意: 注意”0”的特殊处理，且给定的字符串存在无解情况，如"0", "30"等等
         */
        vector<int> dp (len + 1, 0);
        int tmp;

        if (s[0] == '0')
            return 0;

        dp[0] = dp[1] = 1;
        for (int i = 2; i <= len; i++) {
            if (s[i - 1] == '0') {
                /* 不存在前缀0，当s[i - 1]为0时，只能和s[i - 2]组合起来解码 */
                if (s[i - 2] == '0' || s[i - 2] > '2') {
                    /* 如果s[i - 2]为0, 或大于2，则无法解码 */
                    return 0;
                } else {
                    /* s[i - 2]s[i - 1]组合为有效字母 */
                    dp[i] = dp[i - 2];
                }
            } else {
                tmp = 10 * (s[i - 2] - '0') + s[i - 1] - '0';
                if (s[i - 2] != '0' && tmp >= 1 && tmp <= 26) {
                    /* s[i - 2]s[i - 1]组合为有效字母: s[i - 1]可以单独解码 + s[i - 2]s[i - 1]也可以组合解码 */
                    dp[i] = dp[i - 1] + dp[i - 2];
                } else {
                    /* 无法组合，s[i - 1]只能单独解码 */
                    dp[i] = dp[i - 1];
                }
            }
        }

        return dp[len];
    }
};


class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();

        /*
         * 动态规划
         * dp[i]从[0,i]字串解码方法
         * 如果s[i - 1]s[i]为有效字母，即在[1,26]中dp[i] = dp[i - 1] + 1
         * 否则，dp[i] = dp[i - 1]
         * 边界条件: dp[0] = 1
         * 结果为dp[len - 1]
         * 注意: 给定的字符串存在无解情况，如"0", "30"等等
         */
        vector<int> dp (len, 0);
        int tmp;

        if (s[0] == '0')
            return 0;

        dp[0] = 1;
        for (int i = 1; i < len; i++) {
            if (s[i] == '0') {
                /* 不存在前缀0，当s[i]为0时，只能和s[i - 1]组合起来解码 */
                if (s[i - 1] == '0' || s[i - 1] > '2') {
                    /* 如果s[i - 1]为0, 或大于2，则无法解码 */
                    return 0;
                } else {
                    /* s[i - 1]s[i]组合为有效字母 */
                    if (i - 2 >= 0)
                        dp[i] = dp[i - 2];
                    else
                        /* "10" 或 "20"情况 - 只有一种解码方法 */
                        dp[i] = 1;
                }
            } else {
                tmp = 10 * (s[i - 1] - '0') + s[i] - '0';
                if (s[i - 1] != '0' && tmp >= 1 && tmp <= 26) {
                    /* s[i - 1]s[i]组合为有效字母: s[i]可以单独解码 + s[i - 1]s[i]也可以组合解码 */
                    if (i >= 2)
                        dp[i] = dp[i - 1] + dp[i - 2];
                    else
                        dp[i] = dp[i - 1] + 1;
                } else {
                    /* s[i]单独解码 */
                    dp[i] = dp[i - 1];
                }
            }
            //cout << tmp << " " << dp[i] << endl;
        }

        return dp[len - 1];
    }
};
