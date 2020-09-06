

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        /* 相同的数字异或为0，遍历数组并异或，最后的结果就是只出现一次的数字 */
        for (auto num : nums)
            ans ^= num;
        return ans;
    }
};
