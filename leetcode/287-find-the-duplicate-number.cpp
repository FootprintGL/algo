

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
         * 二分法
         * 先猜一个数mid, 统计原数组中小于等于这个中间数的元素个数cnt，如果大于mid
         * 根据抽屉原理，重复元素在[left, mid]
         */
        int left = 1, right = nums.size() - 1;
        int cnt = 0;

        while (left < right) {
            int mid = left + (right - left) / 2;
            cnt = 0;
            for (auto &num : nums)
                if (num <= mid)
                    cnt++;

            if (cnt > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
