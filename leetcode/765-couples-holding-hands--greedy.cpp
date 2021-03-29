

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        /*
         * 贪心算法
         * 遍历每个偶数位置2 * i, 把他的对象安排到他右边的奇数位置2 * i + 1
         * x的对象为x ^ 1
         * 1. x为偶数，x ^ 1为x + 1
         * 2. x为奇数，x ^ 1为x - 1
         */
        int n = row.size();
        int res = 0;

        for (int i = 0; i < n; i = i + 2) {
            /* 位运算符优先级低于比较运算符，需要添加括号 */
            if (row[i] == (row[i + 1] ^ 1))
                /* 已配对，无需交换 */
                continue;

            for (int j = i + 1; j < n; j++) {
                if (row[i] == (row[j] ^ 1)) {
                    /* 交换i + 1, j位置元素 */
                    int tmp = row[i + 1];
                    row[i + 1] = row[j];
                    row[j] = tmp;
                    /* 更新交换次数 */
                    res++;
                    break;
                }
            }
        }

        return res;
    }
};
