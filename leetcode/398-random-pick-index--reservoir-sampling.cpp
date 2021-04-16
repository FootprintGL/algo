

class Solution {
public:
    vector<int> nums;

    Solution(vector<int>& nums) {
        this->nums = nums;
    }

    int pick(int target) {
        /*
         * 蓄水池抽样问题
         * 假设当前正在读第n个数据，我们以1/n的概率保留该数据
         * 否则留下前n - 1个数据中的一个，这样数据流中数据被选择的概率一样
         */
        int index = 0;
        int n = 0;
        for (int i = 0;i < nums.size(); i++) {
            if (nums[i] == target) {
                /* 在目标对象中选取 */
                n++;
                if (rand() % n == 0)
                    /* 以1/n的概率留下该数据 */
                    index = i;
            }
        }

        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

class Solution {
public:
    unordered_map<int, vector<int>> tbl;

    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            tbl[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        return tbl[target][rand() % (tbl[target].size())];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
