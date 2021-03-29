

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        /*
         * 滑动窗口
         * 先把确定满意的客户加起来
         * 再用一个X大小的滑动窗口，看最多能是多少不满意的人变满意
         */
        int max = 0;
        int n = customers.size();

        /* 确定满意的客户数量 */
        for (int i = 0; i < n; i++)
            max += customers[i] * (1 - grumpy[i]);

        /* 叠加初始窗口满意客户增加的数量 */
        for (int i = 0; i < X; i++)
            max += customers[i] * grumpy[i];

        int res = max;
        /* 移动窗口，更新结果 */
        for (int i = X; i < n; i++) {
            max = max - customers[i - X] * grumpy[i - X] + customers[i] * grumpy[i];
            if (max > res)
                res = max;
        }

        return res;
    }
};
