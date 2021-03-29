


class Solution {
public:
    int atmostk(vector<int> &A, int k) {
        int n = A.size();
        int l = 0, r = 0;
        int distinct = 0;
        unordered_map<int, int> cnt;
        int res = 0;

        while (r < n) {
            cnt[A[r]]++;
            if (cnt[A[r]] == 1)
                distinct++;

            while (distinct > k) {
                /* 缩小窗口 */
                cnt[A[l]]--;
                if (cnt[A[l]] == 0)
                    distinct--;
                l++;
            }

            res += r - l + 1;
            /* 扩大窗口 */
            r++;
        }

        return res;
    }

    int subarraysWithKDistinct(vector<int>& A, int K) {
        /*
         * 滑动窗口
         * 恰好由k个不同整数的子数组的个数 = 最多由k个不同整数的子数组个数 - 最多由k - 1个不同整数的子数组个数
         * 最多k个不同整数的子数组个数, 对于长度[l, r]区间内每个子数组都是满足要求的，res要累加的其实是符合条件
         * 的并且以right为右端点的子数组个数，即区间长度r - l + 1
         * 当right到达一个新位置，把left调整到满足题意的位置，当前[l, r]区间内符合条件的并且以right为右端点的
         * 子数组个数为r - l + 1
         */
        return atmostk(A, K) - atmostk(A, K - 1);
    }
};
