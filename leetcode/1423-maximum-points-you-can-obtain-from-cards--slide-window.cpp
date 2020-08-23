

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        /*
         * 拿完k张后，还剩下n - k张
         * 拿一个大小为n - k的窗口，从左往右移动并计算窗口里的点数和
         * 总点数固定，抽k张获得最大点数，则实际求剩下n-k的最点数
         */
        int n = cardPoints.size();
        int i, ans = INT_MAX;
        vector<int> sums(n + 1, 0);

        /* 求前缀和sums */
        for (i = 0; i < n; i++)
            sums[i + 1] = sums[i] + cardPoints[i];
        /*
        for (i = 0; i <= n; i++)
            cout << sums[i] << " ";
        cout << endl;
        */

        /* 计算滑动窗口点数和并更新最小值 */
        for (i = 1; i <= k + 1; i++) {
            if (ans > sums[i + n - k - 1] - sums[i - 1])
                ans = sums[i + n - k - 1] - sums[i - 1];
            //cout << (i + n - k - 1) << " " << (i - 1) << " " << (sums[i + n - k - 1] - sums[i - 1]) << " " << ans << endl;
        }
        //cout << endl;

        return sums[n] - ans;
    }
};
