

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> tbl;
        int ans = 0;

        for (auto &num : nums)
            tbl[num]++;

        for (auto &[num, cnt] : tbl)
            ans += cnt * (cnt - 1) / 2;

        return ans;
    }
};
