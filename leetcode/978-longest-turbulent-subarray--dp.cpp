

class Solution {
public:
    int compare(int a, int b) {
        if (a > b)
            return 1;
        else if (a < b)
            return -1;
        else
            return 0;
    }

    int maxTurbulenceSize(vector<int>& A) {
        /*
         * 滑动窗口
         * 如果比较符号在子数组中的每个相邻元素直接反转，则该子数组为湍流子数组
         * 大于 -> 1, 小于 -> -1, 等于 -> 0
         * 当遇到连续2个符号相等或符号为0时，湍流子数组不成立，划分窗口
         * {9,4,2,10,7,8,8,1,9} -> {1,1,-1,1,-1,0,1,-1}
         * 划分为四个湍流子数组{1}, {1,-1,1,-1}, {0}, {1,-1}
         */
        int n = A.size();
        if (n < 2)
            return 1;

        int left = 0, right = 1;
        int s1, s2;
        int ans = 1;

        while (right < n) {
            s1 = compare(A[right - 1], A[right]);
            if (right == n - 1 || s1 * compare(A[right], A[right + 1]) != -1) {
                if (s1 != 0)
                    ans = max(ans, right - left + 1);
                left = right;
            }
            right++;
        }

        return ans;
    }
};

class Solution {
public:
    int compare(int a, int b) {
        if (a > b)
            return 1;
        else if (a < b)
            return -1;
        else
            return 0;
    }

    int maxTurbulenceSize(vector<int>& A) {
        /*
         * 动态规划
         * dp[i] - 以A[i]结尾的最大湍流子数组的长度
         * 1. dp[i] = dp[i - 1] + 1, 如果A[i] - A[i - 1]和A[i] - A[i + 1]符号相反
         * 2. 否则:
         *      a. 如果A[i] == A[i - 1], dp[i] = 1
         *      b. 如果A[i] != A[i - 1], dp[i] = 2
         */
        int n = A.size();
        if (n < 2)
            return 1;

        vector<int> dp(n, 1);
        int ans = 1;
        int s1, s2, i;

        dp[1] = A[0] == A[1] ? 1 : 2;
        ans = max(dp[0], dp[1]);
        for (i = 2; i < n; i++) {
            s1 = compare(A[i - 1], A[i - 2]);
            s2 = compare(A[i], A[i - 1]);
            if (s1 * s2 == -1)
                dp[i] = dp[i - 1] + 1;
            else if (s2 != 0)
                dp[i] = 2;
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
