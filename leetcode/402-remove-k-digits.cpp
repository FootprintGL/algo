

class Solution {
public:
    string removeKdigits(string num, int k) {
        /*
         * 单调栈
         * "D0D1D2...Dn-1",从左往右找第一个位置i(i > 0)使得Di < Di-1
         * 如果不存在，说明整个数字序列单调不减，删除最后一个元素即可
         * 每次删除一个数字，直到删除k次
         * 考虑从左往右增量的构造最后的答案，可以用一个栈维护当前的答案序列
         * 栈中的元素代表截止到当前位置，删除位置不超过k次个数后，所能得到的最小整数
         * 在使用k个删除次数之前，栈中的序列从栈底到栈顶单调下降
         * 对于每个数字，如果数字小于栈顶元素，我们就不断地弹出栈顶元素，直到
         *      1 栈为空
         *      2 或者新的栈顶不大于当前数字
         *      3 或者已经删除了k为数字
         * 如果我们删除了m < k个，这种情况下我们需要从序列尾部删除额外的k - m个数字
         * 如果最终的数字序列存在前导0，删除前导0
         * 如果数字序列为空，返回0
         */
        string stk, res;
        int len = num.length(), m = 0, i;

        for (i = 0; i < len; i++) {
            char c = num[i];
            while (!stk.empty() && c < stk.back()) {
                /* 栈内大于c的出栈 */
                stk.pop_back();
                m++;
                if (m == k)
                /* 已经移除了k个数字 */
                    break;
            }

            if (m == k)
            /* 已经移除了k个数字 */
                break;

            /* 当前元素入栈 */
            stk.push_back(c);
        }

        /* 构建结果 */
        res = stk + num.substr(i, len - i);
        if (m < k){
            /* 从末尾去掉k - m位 */
            res = res.substr(0, res.length() - (k - m));
        }

        /* 去掉前导0 */
        i = 0;
        while (i < res.length() && res[i] == '0') {
            i++;
        }
        res = res.substr(i, res.length() - i);

        return res.empty() ? "0" : res;
    }
};
