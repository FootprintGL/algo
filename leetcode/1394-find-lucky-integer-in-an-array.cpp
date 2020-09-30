

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = 0;

        /* 排序 + 双指针 */
        sort(arr.begin(), arr.end(), ::greater());
        while (right < n) {
            right = left + 1;
            while (right < n && arr[right] == arr[left])
                right++;

            if (right - left == arr[left])
                return arr[left];

            left = right;
        }

        return -1;
    }
};
