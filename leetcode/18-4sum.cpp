class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int len = nums.size();
        int i, j, k, s;

        sort(nums.begin(), nums.end());
        for (i = 0; i < len; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;

        /* 
         * 双指针 - 和15题类似
         * 固定两个元素i，j，k指向下一个元素，s指向数组最后一个元素
         * 如果三元组的和小于target，向右移动k++，如果大于0，向左移动s--
         * 如果等于target，找到结果，结束查找，处理下一个i + 1
         */
        for (i = 0; i < len - 3; i++) {
            /* 跳过重复元素 */
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            for (j = i + 1; j < len - 2; j++) {
                /* 跳过重复元素 */
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                k = j + 1;
                s = len - 1;
                while (k < s) {
                    if (nums[i] + nums[j] + nums[k] + nums[s] == target) {
                        /* 保持结果 */
                        res.push_back(vector<int>());
                        res.back().push_back(nums[i]);
                        res.back().push_back(nums[j]);
                        res.back().push_back(nums[k]);
                        res.back().push_back(nums[s]);
                        /* 跳过重复元素 */
                        while (k < s && nums[k] == nums[++k]);
                        while (k < s && nums[s] == nums[--s]);
                    } else if (nums[i] + nums[j] + nums[k] + nums[s] < target) {
                        /* 跳过重复元素 */
                        while (k < s && nums[k] == nums[++k]);
                    } else {
                        /* 跳过重复元素 */
                        while (k < s && nums[s] == nums[--s]);
                    }
                }
            }
        }

        return res;
    }
};
