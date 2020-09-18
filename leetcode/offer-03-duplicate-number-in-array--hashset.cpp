

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        /* 如果没有重复数字，则每个元素和坐标位置索引相同 */
        int i = 0;

        while (i < nums.size()) {
            if (nums[i] == i) {
                i++;
                continue;
            }

            if (nums[i] == nums[nums[i]])
                return nums[i];

            /* 必须先对nums[nums[i]]来防止数据覆盖 */
            int tmp = nums[nums[i]];
            nums[nums[i]] = nums[i];
            nums[i] = tmp;
        }

        return -1;
    }
};

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> tbl;

        for (auto &num : nums) {
            if (tbl.count(num))
                return num;
            else
                tbl.insert(num);
        }

        return -1;
    }
};
