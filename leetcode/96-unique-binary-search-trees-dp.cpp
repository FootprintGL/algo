class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        int res, cnt = 0;
        int i, j;

        if (n < 2)
            return 1;

        /*
         * 动态规划
         * 二叉搜索树的左右子树都是二叉搜索树，左子树的值小于根节点和右子树的值
         * G(n) -> 以1,...,n为节点组成的二叉搜索树的个数
         * f(i) -> 以i为根节点的二叉搜索树的个数
         * G(n) = f(1) + f(2) + ... + f(n)
         * f(i) = G(i - 1) * G(n - i)   i = 1 -> n
         * G(n) = G(0) * G(n - 1) + G(1) * G(n - 2) + ... + G(n - 1) * G(0)
         */
        dp[0] = 1;
        dp[1] = 1;
        for (i = 2; i <= n; i++) {
            cnt = 0;
            for (j = 1; j <= i; j++) {
                cnt += dp[j - 1] * dp[i - j];
            }
            dp[i] = cnt;
        }

        return dp[n];
    }
};
