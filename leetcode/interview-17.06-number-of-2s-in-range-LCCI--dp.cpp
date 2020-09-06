
class Solution {
public:
    int countdigit(int n) {
        int ans = 0;
        while (n > 0) {
            ans++;
            n /= 10;
        }
        return ans;
    }

    int power(int n) {
        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans *= 10;
        }
        return ans;
    }

    int numberOf2sInRange(int n) {
        /*
         * 动态规划
         * dp[i] - 前i位组成的数含有2的个数
         * 第i位为0 - dp[i] = 0 * dp[99..9] + dp[i - 1]
         * 第i位为1 - dp[i] = 1 * dp[99..9] + dp[i - 1]
         * 第i位为2 - dp[i] = 2 * dp[99..9] + dp[i - 1] + n % pow(10, i - 1) + 1
         * 第i位大于2 - dp[i] = k * dp[99..9] + dp[i - 1] + pow(10, i - 1)
         * dp[i]和dp[i - 1], dp[99..9]有关
         * dp[i][0] - 前i位组成的数含有2的个数
         * dp[i][1] - dp[99..9], i个9含有2的个数
         */

        /* 计算n一共有多少位 */
        int digit = countdigit(n);
        vector<vector<int>> dp(digit + 1, vector<int> (2, 0));

        dp[1][0] = n % 10 >= 2 ? 1 : 0;
        dp[1][1] = 1;

        cout << digit << endl;

        for (int i = 2; i <= digit; i++) {
            int k = n / power(i - 1) % 10;
            dp[i][0] = k * dp[i - 1][1] + dp[i - 1][0];

            if (k == 2)
                dp[i][0] += n % power(i - 1) + 1;
            else if (k > 2)
                dp[i][0] += power(i - 1);

            if (i < 10)
            /* 防止整数溢出，最多10位，所以9999999999的结果实际是不需要用的 */
                dp[i][1] = 10 * dp[i - 1][1] + power(i - 1);
        }

        return dp[digit][0];
    }
};
