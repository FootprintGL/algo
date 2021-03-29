

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        /*
         * 单调栈
         * 1 栈未满，直接入栈
         * 2 栈满 - 如果当前元素小于栈顶元素,并且剩下的元素足以填满栈，则出栈
         */
        vector<int> res;
        int len = nums.size();
        
        for (int i = 0; i < len; i++) {
            while (res.size() && nums[i] < res.back() && len - i + res.size() > k)
                res.pop_back();

            if (res.size() < k)
                res.push_back(nums[i]);
        }

        return res;
    }
};



/* 下面的解法行不通 */

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res(k, 0);
        int cnt = 0;
        int maxvalue = -1;
        int maxidx = 0;
        /* 子序列尽可能小 */

        for (int i = 0; i < nums.size(); i++) {
            if (cnt < k) {
                res.insert(res.begin(), nums[i]);
                if (maxvalue < nums[i]) {
                    /* 当前元素最大 */
                    maxvalue = nums[i];
                    maxidx = 0;
                } else {
                    /* 最大元素位置后移 */
                    maxidx++;
                }
            } else {
                /* res已放满 */
                if (nums[i] < res.front()) {
                    /* 当前元素更小 - 提出最大的，放入当前 */

                    /* 没有办法继续维护最大值 */
                }
            }
        }

        return res;
    }
};
