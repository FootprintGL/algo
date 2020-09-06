
class Solution {
public:
    int cuttingRope(int n) {
        /*
         * 动态规划 - 做不了，数据方位较大，会一出，对1000000007取模会有偏差，在n(120)较大时结果会错误
         * 尽可能分出多个3和2乘积最大
         * 最优-3: 绳子尽可能切成多个长度为3的片段
         * 次有-2: 最后一段为2，则保留
         * 最差-1: 最后一段为1，则应把3 + 1 替换成2 + 2，因为(2 * 2 > 3 * 1)
         */
        /* n > 1 */
        if (n <= 3)
            return n - 1;
        long M = 1000000007;
        long cnt = n / 3;
        long rem = n % 3;
        long i, j, ans = 1;

        /* 拿出一个3和1分拆成2 + 2 */
        if (rem == 1) {
            cnt--;
        }

        /* 3的cnt次方 */
        for (i = 0; i < cnt; i++) {
            ans = (ans * 3) % M;
        }

        /* 余数处理 */
        if (rem == 1) {
            ans = (ans * 4) % M;
        } else if (rem == 2) {
            ans = (ans * 2) % M;
        }

        return ans;
    }
};
