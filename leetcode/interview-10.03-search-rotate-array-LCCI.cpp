




class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();

        if (n == 1)
            return target == arr[0] ? 0 : -1;

        int l = 0, r = n - 1, m;

        /*
         * 二分法
         * 能判断升序区间的情况，根据目标值的大小移动边界
         * 不能判断升序区间的情况，逐步清楚重复值
         * 没有重复值复杂度为O(logN), 几乎全部是重复值情况复杂度为O(N)
         */
        while (l <= r) {
            m = l + (r - l) / 2;

            if (arr[l] < arr[m]) {
                /* 左边有序 */
                if (target >= arr[l] && target <= arr[m]) {
                    r = m;
                } else {
                    l = m + 1;
                }
            } else if (arr[l] < arr[m]) {
                /* 右边有序 */
                if (target >= arr[m] && target <= arr[r]) {
                    l = m;
                } else {
                    r = m - 1;
                }
            } else {
                if (target == arr[l]) {
                    /* 找到结果 */
                    return l;
                } else {
                    /* 逐个清楚重复值 */
                    l++;
                }
            }
        }

        return -1;
    }
};
