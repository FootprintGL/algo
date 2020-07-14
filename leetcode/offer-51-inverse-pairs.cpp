




class Solution {
public:
    /* 归并排序算法 - 边归并边统计逆序对 */
    void countmerge(vector<int> &nums, int left, int mid, int right, vector<int> &temp, int &count) {
        int i, j, k;

        for (i = left; i <= right; i++)
            temp[i] = nums[i];

        i = left;
        j = mid + 1;
        for (k = left; k <= right; k++) {
            if (i > mid) {
                nums[k] = temp[j];
                j++;
            } else if (j > right) {
                nums[k] = temp[i];
                i++;
            } else if (temp[i] > temp[j]) {
                nums[k] = temp[j];
                j++;
                count += (mid - i + 1);
            } else {
                nums[k] = temp[i];
                i++;
            }
        }
    }

    void dfs(vector<int> &nums, int left, int right, vector<int> &temp, int &count) {
        if (left == right)
            return;
        int mid = left + (right - left) / 2;

        dfs(nums, left, mid, temp, count);
        dfs(nums, mid + 1, right, temp, count);
        countmerge(nums, left, mid, right, temp, count);
    }

    int reversePairs(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;

        vector<int> temp(len, 0);
        int count = 0;

        /*
         * 归并排序
         * 归并时右边元素归位时，左边部分剩余元素都大于该元素，统计逆序对
         */
        dfs(nums, 0, len - 1, temp, count);

        return count;
    }
};
