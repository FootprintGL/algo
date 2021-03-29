

class Solution {
public:
    int maxArea(vector<int>& height) {
        /*
         * 双指针
         * 两边向中间移动，每次移动较矮的（贪心）
         * 边移动边更新最大值
         */
        int vmax = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            vmax = max(vmax, (right - left) * min(height[left], height[right]));
            if (height[left] <= height[right])
                left++;
            else
                right--;
        }

        return vmax;
    }
};
