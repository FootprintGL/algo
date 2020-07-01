class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int min, n = nums.size();
        /* l定义为INT_MIN, 如果数组中有INT_MIN元素，则出错 */
        //int l = INT_MIN, m = INT_MIN, r = INT_MIN;
        long l = LONG_MIN, m = LONG_MIN, r = LONG_MIN;
        int i;

        /* l, m, r分别记录前三个最大的数，遍历数字，循环更新l, m, r */
        for (i = 0; i < n; i++) {
            if (nums[i] > r) {
                l = m;
                m = r;
                r = nums[i];
            } else if (nums[i] > m && nums[i] != r) {
                l = m;
                m = nums[i];
            } else if (nums[i] > l && nums[i] != m && nums[i] != r) {
                l = nums[i];
            }
        }
        
        return (l != LONG_MIN) ? l : r;
    }
};
