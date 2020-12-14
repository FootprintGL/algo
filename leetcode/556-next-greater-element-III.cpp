

class Solution {
public:
    int nextGreaterElement(int n) {
        string nums = to_string(n);
        int len = nums.length(), i, j, k;

        /*
         * 如果nums已经递减，则n为最大元素，返回-1
         * 否则从右向左找到第一个位置使得nums[i] < nums[i + 1]
         * 从i向右搜索最后一个大于nums[i]的元素进行交换，此时i + 1到结尾仍递增有序
         * 在把i + 1到结尾元素反向，得到的值即为结果
         */
        for (i = len - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1])
                break;
        }

        if (i == -1)
        /* nums递减有序，没有更大元素 */
            return -1;

        /* 从i向右找到最后一个大于nums[i]的元素并与nums[i]进行交换 */
        j = i + 1;
        while (j < len && nums[i] < nums[j])
            j++;

        char temp = nums[i];
        nums[i] = nums[j - 1];
        nums[j - 1] = temp;

        /* 反转i + 1到结尾元素 */
        j = i + 1;
        k = len - 1;
        while (j < k) {
            temp = nums[j];
            nums[j] = nums[k];
            nums[k] = temp;
            j++;
            k--;
        }

        /* long - 防止整数溢出 */
        long res = stol(nums);

        return res <= INT_MAX ? res : -1;
    }
};
