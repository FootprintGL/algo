


class Solution {
public:
    int mergesort(vector<int> &nums, int left, int right) {
        if (left == right)
            return 0;

        /* 分拆 */
        int cnt = 0;
        int mid = left + (right - left) / 2;
        int i, j, k = 0;

        cnt += mergesort(nums, left, mid);
        cnt += mergesort(nums, mid + 1, right);

        /* 统计重要翻转对 */
        for (i = left, j = mid + 1; j <= right; j++) {
            /* nums[i] <= 2 * nums[j]会溢出 */
            while (i <= mid && (long)nums[i] <= (long)nums[j] * 2)
                i++;
            cnt += mid - i + 1;
        }

        /* 合并 */
        vector<int> temp(right - left + 1);
        i = left;
        j = mid + 1;
        while (i <= mid || j <= right) {
            if (i > mid) {
                temp[k++] = nums[j++];
            } else if (j > right) {
                temp[k++] = nums[i++];
            } else {
                if (nums[i] <= nums[j])
                    temp[k++] = nums[i++];
                else
                    temp[k++] = nums[j++];
            }
        }
        copy(temp.begin(), temp.end(), nums.begin() + left);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        /* 归并排序
         * 题目要求统计元素左侧大于该元素2倍的元素的个数
         * 假设有2个有序数组，A和B，i指向A，j指向B
         * 如果nums[i] > 2 * nums[j], 则A中i右边的元素都满足条件
         * 边归并边统计
         */
        if (nums.size() == 0)
            return 0;

        return mergesort(nums, 0, nums.size() - 1);
    }
};
