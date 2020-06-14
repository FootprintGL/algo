class Solution {
public:
    int tribonacci(int n) {
        int res, f1, f2, f3;
        int i;

        /* 特殊情况处理 */
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else if (n == 2)
            return 1;
        
        f1 = 0;
        f2 = 1;
        res = f3 = 1;

        for (i = 3; i < n + 1; i++) {
            res = f1 + f2 + f3;
            f1 = f2;
            f2 = f3;
            f3 = res;
        }

        return res;
    }
};
