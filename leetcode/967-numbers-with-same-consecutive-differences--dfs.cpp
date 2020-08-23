

class Solution {
public:
    vector<int> res;
    /* DFS - 从左向右一位一位添加 */
    void helper(int n, int k, int cur, int pre) {
        if (n == 0) {
            res.push_back(cur);
            return;
        }
        if (pre + k <= 9)
            helper(n - 1, k, cur * 10 + pre + k, pre + k);
        /* K为0时只需要计算一次，否则会产生重复解 */
        if (k != 0 && pre - k >= 0)
            helper(n - 1, k, cur * 10 + pre - k, pre - k);
    }

    vector<int> numsSameConsecDiff(int N, int K) {
        /* 特殊情况处理 */
        if (N == 1)
            return {0,1,2,3,4,5,6,7,8,9};
        /* 第一位不能为0 */
        for (int i = 1; i < 10; i++) {
            helper(N - 1, K, i, i);
        }
        return res;
    }
};
