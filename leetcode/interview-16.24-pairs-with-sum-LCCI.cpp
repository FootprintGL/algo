

class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        /* 排序+双指针 */
        vector<vector<int>> res;
        int n = nums.size();
        int left = 0, right = n - 1, sum;

        if (n <= 1)
            return res;

        sort(nums.begin(), nums.end());
        while (left < right) {
            sum = nums[left] + nums[right];
            if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            } else {
                res.push_back({nums[left], nums[right]});
                left++;
                right--;
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        /* 哈希表 */
        unordered_map<int, int> tbl;
        vector<vector<int>> res;

        for (auto &num : nums) {
            if (tbl[target - num]) {
                res.push_back({num, target - num});
                tbl[target - num]--;
            } else {
                tbl[num]++;
            }
        }

        return res;
    }
};
