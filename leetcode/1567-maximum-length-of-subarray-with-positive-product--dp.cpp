


class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        /*
         * 动态规划
         * pos[i] - 表示以nums[i]结尾乘积为正数的最长子数组长度
         * neg[i] - 表示以nums[i]结尾乘积为负数的最长子数组长度
         * 边计算边更新结果
         */
        int n = nums.size();
        vector<int> pos(n + 1, 0);
        vector<int> neg(n + 1, 0);
        int res = 0;

        for (int i = 1; i <= n; i++) {
            if (nums[i - 1] > 0) {
                pos[i] = pos[i - 1] + 1;
                if (neg[i - 1])
                    neg[i] = neg[i - 1] + 1;
                res = max(res, pos[i]);
            } else if(nums[i - 1] < 0) {
                if (neg[i - 1])
                    pos[i] = neg[i - 1] + 1;
                neg[i] = pos[i - 1] + 1;
                res = max(res, pos[i]);
            } else {
                pos[i] = neg[i] = 0;
            }
        }
/*
        for (auto t : pos)
            cout << t << " ";
        cout << endl;

        for (auto t : neg)
            cout << t << " ";
        cout << endl;
*/
        return res;
    }
};
