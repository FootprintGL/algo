

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /* 二分法 */
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] > m) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        //cout << l << " " << r << endl;

        return l;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (auto num : nums)
            sum += num;

        return n * (n + 1) / 2 - sum;
    }
};
