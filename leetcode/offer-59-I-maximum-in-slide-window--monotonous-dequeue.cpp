

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /* 单调队列 */
        vector<int> res;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();

            dq.push_back(i);
            /* 头部的index已经划出窗口，过期了 */
            if (dq.front() < i - k + 1)
                dq.pop_front();

            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }

        return res;
    }
};
