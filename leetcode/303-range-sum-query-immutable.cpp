class NumArray {
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        int sum = 0, len = nums.size();
        int i;

        /* 前缀和 */
        for (i = 0; i < len; i++) {
            sum += nums[i];
            sums.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0)
            return sums[j];
        else
            return sums[j] - sums[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
