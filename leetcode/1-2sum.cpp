class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> map;
        int len = nums.size();
        unordered_map<int, int>::iterator it;
        int i;

        /* 哈希表加速查找 - 查找target - nums[i]在不在表里 */
        for (i = 0; i < len; i++) {
            it = map.find(target - nums[i]);
            if (it != map.end()) {
                /*
                 * 保存结果，结束循环
                 * 注意一个元素不能使用两次，需要判断哈希表里下标不是当前下标
                 */
                res.push_back(it->second);
                res.push_back(i);
                break;
            }
            map.insert({nums[i], i});
        }

        return res;
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> map;
        int len = nums.size();
        unordered_map<int, int>::iterator it;
        int i;

        /* 哈希表加速查找 - 查找target - nums[i]在不在表里 */
        for (i = 0; i < len; i++) {
            map.insert({nums[i], i});
            it = map.find(target - nums[i]);
            if (it != map.end() && i != it->second) {
                /*
                 * 保存结果，结束循环
                 * 注意一个元素不能使用两次，需要判断哈希表里下标不是当前下标
                 */
                res.push_back(it->second);
                res.push_back(i);
                break;
            }
        }

        return res;
    }
};
