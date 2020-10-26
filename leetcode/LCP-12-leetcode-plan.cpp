

class Solution {
public:
    bool check(int limit, vector<int> &time, int m) {
        int maxtime = 0, cursum = 0, nexttime;
        int cnt = 1;

        for (auto &t : time) {
            /* 每组最大值不需要计入 */
            nexttime = min(maxtime, t);
            if (cursum + nexttime <= limit) {
                cursum += nexttime;
                maxtime = max(maxtime, t);
            } else {
                /* 超过limit，就重新分一组 */
                cnt++;
                maxtime = t;
                cursum = 0;
            }
        }

        return cnt <= m;
    }

    int minTime(vector<int>& time, int m) {
        /*
         * 二分法
         * 将一个数组分成m组，使得每份元素之和最大值最小，每份可以任意减掉一个元素
         * 单调最优 - 如果最大值为t可以满足划分要求，t + 1也可以
         * 每组删除最大元素，再检查总和看是否小于等于t
         */
        if (m >= time.size())
            return 0;

        int left = 0, right = 0, mid;
        for (auto &t : time)
            right += t;

        /* 范围为0 - sum{time} */
        while (left < right) {
            mid = left + (right - left) / 2;
            if (check(mid, time, m))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};
