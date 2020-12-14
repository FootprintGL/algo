
class Solution {
public:
    int countrangesummerge(vector<long> &presum, int lower, int upper, int left, int right) {
        if (left == right) {
            return 0;
        } else {
            /* 归并排序模板 */
            int mid = left + (right - left) / 2;
            int count = 0;
            count += countrangesummerge(presum, lower, upper, left, mid);
            count += countrangesummerge(presum, lower, upper, mid + 1, right);

            /* 计算下标对个数 */
            int i = left;
            int l = mid + 1, r = mid + 1;
            while (i <= mid) {
                while (l <= right && presum[l] - presum[i] < lower)
                    l++;
                while (r <= right && presum[r] - presum[i] <= upper)
                    r++;
                count += (r - l);
                i++;
            }

            /* 合并两个排序数组 */
            vector<int> sorted(right - left + 1);
            int p1 = left, p2 = mid + 1, p = 0;

            while (p1 <= mid || p2 <= right) {
                if (p1 > mid) {
                    sorted[p++] = presum[p2++];
                } else if (p2 > right) {
                    sorted[p++] = presum[p1++];
                } else {
                    if (presum[p1] <= presum[p2])
                        sorted[p++] = presum[p1++];
                    else
                        sorted[p++] = presum[p2++];
                }
            }

            /* 更新合并后的结果 */
            for (i = 0; i < sorted.size(); i++)
                presum[left + i] = sorted[i];
            
            return count;
        }
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        /*
         * 归并排序
         * 1. 求前缀和presum, 问题等价于求所有的下标对(i, j), 满足presum[j] - presum[i] -> {lower, upper}
         * 2. 假如给定2个有序数组n1, n2, 试着找出所有的下标对(i, j), 满足n2[j] - n1[i] -> {lower, upper}
         * 3. l, r分别指向n2的起始位置，考察n1的第i个元素
         *      a. 向右移动l，直到满足n2[l] >= n1[i] + lower为止，l右边的元素满足大于等于n1[i] + lower
         *      b. 向右移动r，直到满足n2[r] > n1[i] + upper, r左边的元素满足小于等于n1[i] + upper
         *      c. [l,r)中所有下标j，都满足n2[j] - n1[i] -> {lower, upper}
         * 4. 这样我们就可以统计得到满足条件的下标对(i, j)的数量
         * 采用归并排序的方式，能够得到左右两个数组排序后的形式，以及对应的下标对数量。对于原数组而言，若要找出全部的 
         * 下标对数量，只需要在额外找出左端点在左侧数组，同时右端点在右侧数组的下标对数量。
         */
        long n = nums.size(), sum = 0;
        vector<long> presum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            presum[i + 1] = sum;
            //cout << nums[i] << " ";
        }
        //cout << endl;
/*
        for (auto t : presum)
            cout << t << " ";
        cout << endl;
*/
        return countrangesummerge(presum, lower, upper, 0, n);
    }
};





/* 暴力算法(O(n ^ 2)) - 超时 */
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        /* 前缀和 */
        long res = 0, sum;
        int i, j, n = nums.size();

        /* 统计[lower, upper]范围内的区间和 */
        for (i = 0; i < n; i++) {
            sum = 0;
            for (j = i; j < n; j++) {
                sum += nums[j];
                if (sum >= lower && sum <= upper)
                    res++;
            }
        }

        return res;
    }
};
