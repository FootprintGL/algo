

class Solution {
public:
    /* 排序并判断等差数列 */
    bool helper(vector<int> &vec) {
        int size = vec.size();

        if (size <= 2)
            return true;

        sort(vec.begin(), vec.end());
        int delta = vec[1] - vec[0];
        for (int i = 1; i < size - 1; i++) {
            if (vec[i + 1] - vec[i] != delta)
                return false;
        }

        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        /* 取出子数组，排序，判断等差数列 */
        vector<bool> res;
        for (int i = 0; i < l.size(); i++) {
            vector<int> tmp(nums.begin() + l[i], nums.begin() + r[i] + 1);
            res.push_back(helper(tmp));
        }
        return res;
    }
};
