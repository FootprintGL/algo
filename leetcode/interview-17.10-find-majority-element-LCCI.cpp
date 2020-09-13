
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return -1;

        int major = nums[0];
        int count = 1;

        /*
         * 摩尔投票算法
         * 线性时间和常数空间查找大部分元素的算法
         * 最简单的形式就是查找数组中重复出现超过一半以上n/2的元素
         * 先决条件：1 出现一半以上的元素只有一个，2 这个元素一定存在
         */
        /* 查找多数元素 */
        for (auto num : nums) {
            if (num == major)
                count++;
            else
                count--;
            if (count == 0) {
                major = num;
                count = 1;
            }
        }

        //cout << count << " " << major << endl;
        /* 验证结果 */
        count = 0;
        for (auto num : nums)
            if (major == num)
                count++;

        return count > n / 2 ? major : -1;
    }
};
