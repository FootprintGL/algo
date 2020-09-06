




class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        /* 哈希表统计每个元素出现的此时 */
        vector<int> res(2, 0);
        unordered_map<int, int> map;

        for (auto num : nums) {
            map[num]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (map.find(i + 1) == map.end())
                res[1] = i + 1;
            else if (map[i + 1] == 2)
                res[0] = i + 1;
        }

        return res;
    }
};

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2, 0);
        sort(nums.begin(), nums.end());
        res[1] = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                /* 找到重复元素 */
                res[0] = nums[i - 1];
            } else if (nums[i] > nums[i - 1] + 1) {
                /* 正常nums[i] == nums[i - 1] */
                res[1] = nums[i - 1] + 1;
            }
        }

        if (nums[nums.size() - 1] != nums.size())
            res[1] = nums.size();

        return res;
    }
};
