class Solution {
public:
    int fib(int N) {
        /* 从0开始 */
        vector<int> res (N + 1, 0);
        int i;
        
        if (N == 0)
            return 0;
        else if (N == 1)
            return 1;

        res[0] = 0;
        res[1] = 1;

        for (i = 2; i < N + 1; i++) {
            res[i] = res[i - 1] + res[i - 2];
        }

        return res[N];
    }
};

/* 空间优化 */
class Solution {
public:
    int fib(int N) {
        /* 从0开始 */
        int res, f1, f2;
        int i;

        if (N == 0)
            return 0;
        else if (N == 1)
            return 1;

        f1 = 0;
        f2 = 1;

        for (i = 2; i < N + 1; i++) {
            res = f1 + f2;
            f1 = f2;
            f2 = res;
        }

        return res;
    }
};
