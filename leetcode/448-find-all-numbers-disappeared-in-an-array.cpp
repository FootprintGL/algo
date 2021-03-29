class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        /*
         * nums中数字范围为[1, n]，且nums的长度为n
         * 遍历nums, 每遇到一个x，让nums[x - 1]增加n，增加之后的数必然大于n
         * 遍历nums，如果nums[i]不大于n，说明没有遇到过数i + 1
         */
        int n = nums.size();
        vector<int> res;

        for (int i = 0; i < n; i++) {
            nums[(nums[i] - 1) % n] += n;
        }
        
        for (int i = 0; i < n; i++)
            if (nums[i] <= n)
                res.push_back(i + 1);

        return res;
    }
};



class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        /* 将所有正数作为数组下标来标记数字出现与否 */
        vector<int> res;
        int i;

        /* 用负数标记出现的数字 */
        for (i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] = -1 * nums[abs(nums[i]) - 1];
        }

        /* 查找缺失的数字 */
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                res.push_back(i + 1);
        }

        return res;
    }
};
