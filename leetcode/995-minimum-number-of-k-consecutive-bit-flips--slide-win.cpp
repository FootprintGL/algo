

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        /*
         * 滑动窗口
         * 位置i的状态和它被前面K - 1个元素翻转的次数（奇偶性）有关
         * 利用队列模拟滑动窗口，记录前面K - 1个元素中，从哪些位置起始的子区间进行了翻转
         * 从左往右滑动窗口,如果当前位置i需要翻转,则把该位置存储到队列中，遍历到新位置j (j < i + k)时
         * 队列中元素的个数代表了i被前面k - 1个元素翻转的次数
         * 1 当A[i]为0,如果i位置被翻转了偶数次，翻转后仍为0，当前元素需要翻转
         * 2 当A[i]为1,如果i位置被反转了奇数次，反转后为0，当前位置需要翻转
         * 当len(qu) % 2 == A[i]时，当前元素需要翻转
         * 当i + K > N时，说明需要翻转大小为k的子区间，但后面剩余的元素不到k个了，返回-1
         */
        int n = A.size();
        queue<int> qu;
        int res = 0;

        for (int i = 0; i < n; i++) {
            if (!qu.empty() && qu.front() + K <= i)
            /* qu.front超出i - K窗口，从队列移出 */
                qu.pop();

            if (qu.size() % 2 == A[i]) {
                /* 需要翻转 */
                if (i + K > n)
                    /* 剩下的数不足k，返回-1 */
                    return -1;
                /* 对位置i进行了翻转，更新反转次数 */
                qu.push(i);
                res++;
            }
        }

        return res;
    }
};
