

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        /*
         * 滑动窗口
         * 题目实际是求所有等差子数组和长度
         * 如果等差子数组的长度为len, 则该子数组包含
         * len - 2个长度为3的等差数组
         * len - 3个长度为4的等差数组
         * ... ...
         * 1个长度为len的等差数组
	 * 长度为len的等差子数组个数为(n - 1) * (n - 2) / 2
         * 把数组分为若干个等差数组，计算长度累加结果即可
         */
        int n = A.size();
        if (n < 3)
            return 0;

        int ans = 0, len;
        int left = 0, right = 2;

        while (right < n) {
            if (A[right] - A[right - 1] != A[right - 1] - A[right - 2]) {
                /* right不属于前面的等差数组 */
                len = right - left;
                left = right - 1;
                ans += (len - 2) * (len - 1) / 2;
            } else if (right == n - 1) {
                /* 最后一个元素 */
                len = right - left + 1;
                ans +=  (len - 2) * (len - 1) / 2;
            }

            right++;
        }

        return ans;
    }
};
