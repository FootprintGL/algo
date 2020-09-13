

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        /*
         * 尽量让更多的负数变成整数
         * 如果K小于等于负数的个数，则选择最小的K个元素反转
         * 如果K大于负数的个数，所有的负数变成正数后
         * 如果剩下的转变次数为偶数，则选择其中任何一个改变还保持偶数
         * 如果是奇数，最终会有一个负数，挑绝对值最小的应用和最大
         */
        sort(A.begin(), A.end());
        int n = A.size(), i, ans = 0, absmin = 101;

        for (i = 0; i < n; i++) {
            /* 寻找绝对值最小值 */
            if (absmin > abs(A[i]))
                absmin = abs(A[i]);

            /* 如果还有变换机会，把负数变成正数 */
            if (K > 0 && A[i] < 0) {
                A[i] = -1 * A[i];
                K--;
            }

            /* 累加和 */
            ans += A[i];
        }

        //cout << ans << " " << absmin << endl;

        /* 还剩奇数次，调绝对值最小的应用 */
        if (K % 2 == 1)
            ans -= 2 * absmin;

        return ans;
    }
};
