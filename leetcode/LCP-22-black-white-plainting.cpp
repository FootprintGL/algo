

class Solution {
public:
    int factorial(int n) {
        int res = 1;
        for (int i = 1; i <= n; i++)
            res *= i;
        //cout << res << " " << n << endl;
        return res;
    }

    int comb(int n, int i) {
        int res = factorial(n) / (factorial(i) * factorial(n - i));
        //cout << res << " " << n << " " << i << endl;
        return res;
    }

    int paintingPlan(int n, int k) {
        /*
         * 数学题 - 排列组合
         * div = k / n, rem = k % n
         * i行j列会涂: i * n + j * n - i * j = k
         * 搜索满足 i * n + j * n - i * j = k条件的i，j
         *      1. i == j时，2 * C(n, i) * C(n, j) - C(n, i)表示组合
         *      2. i !=j时，C(n, i) * C(n, j)
         * 累加和即为结果
         * C(n, i) = F(n) / (F(i) * F(n - i)) - C表示组合，F表示阶乘
         */
        if (k == 0 || k == n * n)
            return 1;

        int i, j, res = 0;

        //cout << div << " - " << rem << endl;
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= n; j++) {
                if ((i + j) * n - i * j == k) {
                    //cout << i << " " << (div - i) << endl;
                    res += comb(n, i) * comb(n, j);
                }
            }
        }

        return res;
    }
};
