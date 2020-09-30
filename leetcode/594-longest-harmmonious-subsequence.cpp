
class Solution {
public:
    int findLHS(vector<int>& nums) {
        /* 哈希表 */
        unordered_map<int, int> tbl;
        int ans = 0;
        int pre = 0, cur = 1;

        for (auto &num : nums)
            tbl[num]++;

        for (auto &[num, cnt] : tbl) {
            if (tbl.count(num + 1)) {
                ans = max(ans, cnt + tbl[num + 1]);
            }
        }

        return ans;
    }
};

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        int pre = 0, cur = 1;

        /* 排序 - 找最长的相差1的相邻子数组 */
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                cur++;
            } else if (nums[i] - nums[i - 1] == 1) {
                if (pre != 0 && ans < pre + cur)
                    ans = pre + cur;
                pre = cur;
                cur = 1;
            } else {
                if (pre != 0 && ans < pre + cur)
                    ans = pre + cur;
                pre = 0;
                cur = 1;
            }
            //cout << i << " " << pre << " " << cur << " " << ans << endl;
        }

        /* 最后一组数据还没有处理 - 如[1,1,2,2] */
        if (pre != 0 && ans < pre + cur)
            ans = pre + cur;

        return ans;
    }
};
