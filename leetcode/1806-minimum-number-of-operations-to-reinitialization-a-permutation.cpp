

class Solution {
public:
    int reinitializePermutation(int n) {
        /*
         * 找规律
         * 每次操作，0和n - 1不会改变位置，对于[1, n - 2]
         * 如果i % 2 == 0, arr[i] = perm[i / 2]
         * 如果i % 2 == 1, arr[i] = perm[n / 2 + (i - 1) / 2]
         * 当数字1回到原来的位置,perm回到排列初始值，所以只需要考虑1的位置变化
         *      i < n / 2: i = 2 * i
         *      i > n / 2: i = (i - n / 2) * 2 + 1
         *      i == n / 2: i = 1
         */
        int res = 0, k = n / 2, t = 1;

        do {
            if (t < k)
                t = 2 * t;
            else
                t = (t - k) * 2 + 1;
            res++;
        } while (t != 1);

        return res;
    }
};
