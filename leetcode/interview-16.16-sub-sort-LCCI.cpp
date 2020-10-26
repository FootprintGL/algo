

class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        /*
         * 对于a[i], 如果左边存在大于它的数，a[i]肯定属于需要排序空间
         * 对于a[i], 如果右边存在小于它的数，a[i]肯定属于需要排序空间
         * 只需要找到最右边的那个数，使得左边存在大于它的数
         * 和最左边的那个数，使得右边存在小于它的数
         * 维护最大最小值2次遍历
         */
        int n = array.size();

        if (n < 2)
            return {-1, -1};

        int maxn = INT_MIN, minn = INT_MAX;
        int l = -1, r = -1, i;

        /* 寻找右边界，使得左边有大于它的数 */
        for (i = 0; i < n; i++) {
            if (array[i] < maxn)
                r = i;
            else
                maxn = array[i];
        }

        /* 寻找左边界，使得右边有小于它的数 */
        for (i = n - 1; i >= 0; i--) {
            if (array[i] > minn)
                l = i;
            else
                minn = array[i];
        }

        return {l, r};
    }
};
