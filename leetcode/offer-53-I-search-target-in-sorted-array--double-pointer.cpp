

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /* 二分法 */
        int n = nums.size();
        int cnt = 0;
        int l = 0, r = n - 1, m;

        if (n == 0)
            return 0;

        while (l <= r) {
            m = l + (r - l) / 2;

            if (nums[m] < target) {
                /* 在右边 */
                l = m + 1;
            } else if (nums[m] > target) {
                /* 在左边 */
                r = m - 1;
            } else {
                int s = m;

                /* 向右查找target */
                while (s < n && nums[s] == target)
                    s++;
                cnt += s - m;

                //cout << m << " " << s << " " << cnt << endl;

                /* 向左查找 */
                s = m;
                while (s >= 0 && nums[s] == target)
                    s--;
                cnt += m - s;

                //cout << m << " " << s << " " << cnt << endl;

                /* 多统计了一次 */
                cnt--;
                break;
            }
        }

        return cnt;
    }
};
