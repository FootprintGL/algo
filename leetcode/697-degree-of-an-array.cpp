


class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> tbl;
        vector<vector<int>> freqs;
        int res = INT_MAX, i, maxfreq = 0;

        /* 哈希表 */
        for (i = 0; i < nums.size(); i++)
            tbl[nums[i]].push_back(i);

        for (auto &[num, index] : tbl) {
            if (index.size() > maxfreq) {
                freqs.clear();
                freqs.push_back(index);
                maxfreq = index.size();
            } else if (index.size() == maxfreq) {
                freqs.push_back(index);
            }
        }

        for (auto &index : freqs) {
            res = min(res, index[index.size() - 1] - index[0] + 1);
        }

        return res;
    }
};
