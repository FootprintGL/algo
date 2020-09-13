
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        if (n <= 1)
            return ans;

        int left = 0, right = n - 1;
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                left++;
            } else if (nums[left] + nums[right] > target) {
                right--;
            } else {
                ans.push_back(nums[left]);
                ans.push_back(nums[right]);
                return ans;
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        if (n <= 1)
            return ans;

        unordered_map<int, int> dic;

        for (auto num : nums)
            dic[num]++;

        for (auto num : nums) {
            if (target - num == num) {
                if (dic[num] >= 2) {
                    ans.push_back(num);
                    ans.push_back(num);
                    return ans;
                }
            } else if (dic.count(target - num)) {
                ans.push_back(num);
                ans.push_back(target - num);
                return ans;
            }
        }

        return ans;
    }
};
