

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        vector<string> res(n);
        unordered_map<int, int> tbl;
        int i;

        /* tbl记录元素坐标 */
        for (i = 0; i < n; i++)
            tbl[nums[i]] = i;

        /* 分数由高到底排序 */
        sort(nums.begin(), nums.end(), std::greater<int>());

        if (n == 1) {
            res[tbl[nums[0]]] = "Gold Medal";
            return res;
        }

        if (n == 2) {
            res[tbl[nums[0]]] = "Gold Medal";
            res[tbl[nums[1]]] = "Silver Medal";
            return res;
        }

        /* 依次发奖牌 */
        res[tbl[nums[0]]] = "Gold Medal";
        res[tbl[nums[1]]] = "Silver Medal";
        res[tbl[nums[2]]] = "Bronze Medal";
        for (int i = 3; i < nums.size(); i++) {
            res[tbl[nums[i]]] = to_string(i + 1);
        }

        return res;
    }
};
