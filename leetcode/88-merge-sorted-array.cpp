

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /* 双指针 - 从后往前依次比较放置 */
        int p = m + n - 1;
        int p1 = m - 1;
        int p2 = n - 1;

        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p--] = nums1[p1--];
            } else {
                nums1[p--] = nums2[p2--];
            }
        }

        while (p2 >= 0)
            nums1[p--] = nums2[p2--];
/*
        for (auto num : nums1)
            cout << num << " ";
        cout << endl;
*/
    }
};
