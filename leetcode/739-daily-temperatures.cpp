class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res (n, 0);
        stack<int> s;
        int i;

        /*
         * 单调栈 - 找每个元素下一个比它大的元素
         * 堆栈里存放数组下标，元素递减时持续压栈，遇到比栈顶下表元素大时开始弹栈
         * 边更新结果（i - s.top()），边持续弹栈，直到小于栈顶下标元素
         * 当前元素入栈，处理下一个元素
         */
        for (i = 0; i < n; i++) {
            if (!s.empty()) {
                if (T[i] <= T[s.top()]) {
                    /* 元素递减 - 持续压栈 */
                    s.push(i);
                    continue;
                } else {
                    while (!s.empty() && T[i] > T[s.top()]) {
                        /* 更新结果 - 持续弹栈，直到小于等于栈顶指向元素 */
                        res[s.top()] = i - s.top();
                        s.pop();
                    }
                    /* 当前元素下标入栈 */
                    s.push(i);
                }
            } else {
                /* 压栈 - 空stack */
                s.push(i);
            }
        }

        /* 栈里的元素后面没有更大的元素 - 数组初始化为0，下面的逻辑可以跳过 */
        /*while (!s.empty()) {
            res[s.top()] = 0;
            s.pop();
        }*/

        return res;
    }
};
