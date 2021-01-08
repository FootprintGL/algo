

class Solution {
public:
    void dump(vector<int> &presum) {
        for (auto &t : presum)
            cout << t << " ";
        cout << endl;
    }

    int longestWPI(vector<int>& hours) {
        /*
         * 单调栈
         * 我们将大于8小时的一天记为1分，小于等于8小时的记为-1分，然后对得分数组求前缀和
         * 题目求表现良好时间段的最大长度，即求最长的一段，是的1的个数大于-1的个数
         * 也就是求最长的一段，其和大于0，那么也就是找出前缀和presum中的两个索引i，j
         * 使得j - i最大，且保证presum[j] - presum[i]大于0。问题转换为求presum
         * 数组中的一个最长上坡，可以用单调栈实现 - 同962类似
         */
        int n = hours.size();
        vector<int> presum(n + 1, 0);
        int res = 0;

        /* 构建得分数组 */
        for (int i = 0; i < n; i++) {
            if (hours[i] > 8)
                hours[i] = 1;
            else
                hours[i] = -1;
        }
        //dump(hours);

        /* 构建得分数组前缀和 */
        for (int i = 1; i <= n; i++) {
            presum[i] = presum[i - 1] + hours[i - 1];
        }
        //dump(presum);

        /* 构建单调栈 */
        vector<int> stk;
        stk.push_back(0);
        for (int i = 1; i <= n; i++) {
            if (presum[stk.back()] > presum[i]) {
                stk.push_back(i);
            }
        }

        /* 从右向左遍历更新结果 */
        for (int i = n; i >= 0; i--) {
            while (!stk.empty() && presum[stk.back()] < presum[i]) {
                //cout << i << " " << stk.back() << " " << stk.size() << endl;
                res = max(res, i - stk.back());
                stk.pop_back();
            }
        }

        return res;
    }
};
