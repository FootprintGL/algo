


class Solution {
public:
    int reachNumber(int target) {
        /*
         * 假设移动了k次，最终位置为1,2,3,...,k前面添加+/-号求和的值
         * 数轴左右对称，只需要考虑右边情况即可
         * k为最小的满足s = 1 + 2 + ... + k >= target的正整数
         * 如果s等于target，k即为结果。
         * 如果s大于target，需要把一些数加上负号，使最后求和的值等于target
         * delta = s - target
         * 1 如果delta为偶数需要找出若干个数变为负号，并且它们的和为delta/2
         * 可以证明一定能找到
         * a 如果delta/2 <= k, 选delta/2即可
         * b 如果delta/2 > k, 先选k，再在1, 2, ..., k - 1选取若干，使得和为delta/2 - k，问题规模搜小
         *   显然delta/2 <= 1 + 2 + ... + k, 所以一定能选到
         * 2 如果delta为奇数，则delta/2为奇数，无法选出，只需考虑k + 1/k + 2, 求出1 ～ k + 1/k + 2的和
         *   它们中必有一个和1 ～ k的和奇偶性不同，此时delta为偶数，可以选出若干个数，满足要求
         */
        int sum = 1, k = 1;

        if (target < 0)
            target *= -1;

        while (sum < target) {
            k++;
            sum += k;
        }

        //cout << k << " " << sum << " " << target << endl;
        int delta = sum - target;
        if (delta % 2) {
            if (k % 2)
                k += 2;
            else
                k++;
        }

        return k;
    }
};
