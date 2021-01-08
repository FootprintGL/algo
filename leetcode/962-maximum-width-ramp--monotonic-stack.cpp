

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        /*
         * 单调栈
         * 首先把A数组中以A[0]开头的递减序列抽取出来，最大宽度坡一定是以这个序列中的某一个i为坡底的
         * 假设存在某个元素位置k不存在于上面的递减序列中，且有最大宽度j - k, 这也说明k位置元素一定
         * 是小于前面所有元素的，否则就会有更长的宽度，k一定会被加入到序列中，与假设矛盾, 不存在这样的k
         * 逆向遍历数组，每次遇到元素大于栈顶的就可以计算宽度,然后将栈顶弹出，因为是逆序遍历的,所以这个
         * 宽度一定是栈顶这个坡底i所能形成的最大宽度了，逆序遍历再往前的话即使大于栈顶，形成的宽度减小
         * 所以这个栈顶是可以直接pop出来的遍历所有坡底求最大值即可
         */
        vector<int> stk;
        int n = A.size();
        int res = 0;

        /* 构建A[0]开头的严格递减序列 */
        stk.push_back(0);
        for (int i = 1; i < n; i++) {
            if (A[stk.back()] > A[i])
                stk.push_back(i);
        }

        /* 从右往左遍历并更新结果 */
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && A[stk.back()] <= A[i]) {
                res = max(res, i - stk.back());
                stk.pop_back();
            }
        }

        return res;
    }
};
