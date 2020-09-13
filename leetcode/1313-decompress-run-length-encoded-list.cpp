
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        for (int i = 0; i < n; i = i + 2) {
            int freq = nums[i];
            int val = nums[i + 1];

            for (int j = 0; j < freq; j++)
                res.push_back(val);
        }

        return res;
    }
};
