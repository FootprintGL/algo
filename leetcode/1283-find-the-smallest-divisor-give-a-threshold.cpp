

class Solution {
public:
    int upperdiv(int a, int b) {
        return (a % b) ? a / b + 1 : a / b;
    }

    int sumdiv(vector<int> &nums, int div) {
        int res = 0;
        for (auto &num : nums) {
            res += upperdiv(num, div);
        }
        return res;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        /* 二分法
         * l = 1, r = maxelement(nums)
         * 选取中间数mid为除数计算除法结果和
         * 如果sum > threshold, 说明mid不满足需求，区间[l, mid]不存在满足条件的数
         * 继续在(mid, r]中进行查找
         * 如果sum <= threshold, 说明mid满足要求，题目要求除数尽可能小
         * 可以忽略区间(mid, r]而在区间[l, mid)中进行查找
         */
        int left = 1, right, mid;
        int res = -1;

        /* 最大值 */
        right = nums[0];
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > right)
                right = nums[i];

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int sum = sumdiv(nums, mid);
            //cout << left << " " << right << " " << mid << " " << sum << endl;
            if ( sum > threshold) {
                left = mid + 1;
            } else {
                res = mid;
                right = mid - 1;
            }
        }

        return res;
    }
};
