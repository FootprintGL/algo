

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> tbl;
        int n = arr.size();
        int target = n * 1 / 4;

        for (auto &a : arr)
            tbl[a]++;

        for (auto &[a, cnt] : tbl)
            if (cnt > target)
                return a;

        return -1;
    }
};
