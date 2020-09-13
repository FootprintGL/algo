
class Solution {
public:
    void reverse(vector<int> &nums, int start, int end) {
        while (start < end) {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;
            end--;
        }
    }

    /* 整个反转，前k个反转，后面n - k个反转 */
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};

/* 超时了 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if (n < 2)
            return;

        while (k > 0) {
            int tmp = nums[n - 1];
            for (int i = n - 1; i >= 1; i--)
                nums[i] = nums[i - 1];
            nums[0] = tmp;
            k--;
        }
    }
};
