


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        /* 双指针 */
        vector<string> res;

        int n = nums.size();
        int left = 0, right = 0;

        while (right < n) {
            right = left + 1;
            while (right < n && nums[right] == nums[right - 1] + 1)
                right++;

            string s = to_string(nums[left]);
            if (left != right - 1) {
                s += "->";
                s += to_string(nums[right - 1]);
            }
            res.push_back(s);
            left = right;
        }

        return res;
    }
};
