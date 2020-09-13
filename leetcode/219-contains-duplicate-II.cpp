

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /*
         * 哈希表
         * i指向第0个元素，j指向第k - 1个元素，i ~ j所有元素放入map
         * 如果nums[k]在map里，表示找到满足条件的数据队
         * i,j同时后移，nums[j]放入map，nums[i]移除map
         * 继续检查nums[k]是否在map中
         */
        int n = nums.size();
        if (n < 2 || k == 0)
            return false;

        unordered_map<int, int> tbl;
        int i, j;

        /* 0 ～ k - 1元素放入map，并检查有没有相同元素 */
        for (i = 0; i < min(k, n); i++) {
            if (tbl.count(nums[i]))
                return true;
            tbl[nums[i]]++;
        }

        for (j = 0; i < n; i++, j++) {
            if (tbl[nums[i]] > 0)
                return true;
            tbl[nums[j]]--;
            tbl[nums[i]]++;
        }

        return false;
    }
};
