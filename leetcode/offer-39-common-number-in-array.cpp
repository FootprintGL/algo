

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> tbl;

        for (auto &num : nums) {
            tbl[num]++;
            if (tbl[num] > n / 2)
                return num;
        }

        return -1;
    }
};
