class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int delta = INT_MAX, len = nums.size();
        bool less = true;
        int i, j, k;

        /* 排序数组 */
        sort(nums.begin(), nums.end());
        /* 
         * 双指针 - 和15题类似
         * 固定一个元素i，j指向下一个元素，k指向数组最后一个元素
         * 如果等于target，找到结果，结束查找。如果三元组的和小于target，向右移动j++，如果大于0，向左移动k--
         * delta记录当前三元组的和target的差值，less标记三元组的和是大于target，还是小于target
         * 随着循环的深入delta会越来越小，循环结束就是要找的结果
         */
        
        for (i = 0; i < len - 2; i++) {
            /* 跳过重复元素 */
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            j = i + 1;
            k = len - 1;
            while (j < k) {
                if ((nums[i] + nums[j] + nums[k]) == target) {
                    return target;
                } else if ((nums[i] + nums[j] + nums[k]) < target) {
                    if ((target - (nums[i] + nums[j] + nums[k])) < delta ) {
                        delta = target - (nums[i] + nums[j] + nums[k]);
                        less = true;
                    }
                    /* 跳过重复元素 */
                    while (j < k && nums[j] == nums[++j]);
                } else {
                    if ((nums[i] + nums[j] + nums[k] - target) < delta ) {
                        delta = nums[i] + nums[j] + nums[k] - target;
                        less = false;
                    }
                    /* 跳过重复元素 */
                    while (j < k && nums[k] == nums[--k]);
                }
            }
        }

        /* 返回最后的结果 */
        if (less)
            return (target - delta);
        else
            return (target + delta);
    }
};
