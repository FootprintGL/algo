class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        int i, j, k;

        /* 数组元素小于3个 - 返回空 */
        if (len < 3)
            return res;

        /* 排序数组 */
        sort(nums.begin(), nums.end());
        /* 全正或全负数组 - 返回空 */
        if (nums[0] > 0 || nums[len - 1] < 0)
            return res;
        /* 
         * 双指针
         * 固定一个元素i，j指向下一个元素，k指向数组最后一个元素
         * 如果三元组的和小于0，向右移动j++，如果大于0，向左移动k==
         * 如果等于0，找到结果，结束查找，处理下一个i + 1
         */
        for (i = 0; i < len - 2; i++) {
            /* 固定元素大于0，结束循环 */
            if (nums[i] > 0)
                break;
            /* 跳过重复元素 */
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            j = i + 1;
            k = len - 1;
            while (j < k) {  
                if (nums[i] + nums[j] + nums[k] == 0) {
                    /* 找到三元组 */
                    res.push_back(vector<int>());
                    res.back().push_back(nums[i]);
                    res.back().push_back(nums[j]);
                    res.back().push_back(nums[k]);
                    /* 跳过重复元素 */
                    while (j < k && nums[j] == nums[++j]);
                    while (j < k && nums[k] == nums[--k]);
                } else if (nums[i] + nums[j] + nums[k] < 0){
                    /* 跳过重复元素 */
                    while (j < k && nums[j] == nums[++j]);
                } else {
                    /* 跳过重复元素 */
                    while (j < k && nums[k] == nums[--k]);
                }
            }
        }

        return res;
    }
};

