

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {

        /*
         * 动态规划
         * dp[i] - 前i本书书架的最小高度
         * 1. book i放在新的一层, dp[i] = dp[i - 1] + height[i]
         * 2. 可以从前面多拿些书和i一起放到新的一层，只要sum(width[j + 1], width[j + 2], ..., width[i]) <= shelf_width
         * dp[i] = min(dp[j] + max(height[j + 1], height[j + 2], ..., height[i]))
         * 结果为dp[n]
         */
        int n = books.size();
        vector<int> dp(n + 1, 0);
        int maxheight, sumwidth;
        int i, j;

        for (i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + books[i - 1][1];
            sumwidth = books[i - 1][0];
            maxheight = books[i - 1][1];
            for (j = i - 1; j > 0; j--) {
                sumwidth += books[j - 1][0];
                if (sumwidth > shelf_width)
                    break;
                maxheight = max(maxheight, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + maxheight);
            }
            //cout << dp[i] << " ";
        }
        //cout << endl;

        return dp[n];
    }
};
