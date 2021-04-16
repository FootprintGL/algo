
class Solution {
public:
    void dump(vector<int> &arr) {
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int trap(vector<int>& height) {
        /*
         * 动态规划
         * i处能水能达到的最大高度为向左和向右的最大高度的最小值
         * i处能接的水量为i处水能达到的最大高度减去i的高度height[i]
         * 从左到右遍历计算leftmax[i] = max(leftmax[i - 1], height[i])
         * 从右向左遍历计算rightmax[i] = max(rightmax[i + 1], height[i])
         * 遍历统计 sum: {min(leftmax[i], rightmax[i]) - height[i]}
         *
         * 双指针
         * 维护两个指针l，r，以及两个变量lmax, rmax, 初始化时l = 0, r = n - 1, lmax = 0, rmax = 0
         * 1 h[l]/h[r]更新lmax/rmax的值
         * 2 如果h[l] < h[r], 则必有lmax < rmax，下标l能接水lmax - h[l], l右移
         * 3 如果h[l] >= h[r],则必有lmax >= rmax, 下表r处能接水rmax - h[r], r左移
         * l/r相遇时结束得到总的蓄水量
         */
        int n = height.size();

        if (n == 0)
            return 0;

        int sum = 0;
        int l = 0, r = n - 1, lmax = 0, rmax = 0;

        while (l < r) {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if (height[l] < height[r]) {
                sum += lmax - height[l];
                l++;
            } else {
                sum += rmax - height[r];
                r--;
            }
        }

        return sum;
    }
};


class Solution {
public:
    void dump(vector<int> &arr) {
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int trap(vector<int>& height) {
        /*
         * 单调栈
         * 维护一个单调栈，里面存放的是下标，满足从栈底到栈顶下标对应的元素递减
         * 从左到右遍历到i时，如果栈内至少2个元素，记栈顶top和top下一个元素left
         * 则一定有h[l] >= h[top]。如果h[l] > h[top],则得到一个可以接水的区域
         * 该区域的宽度为i - left - 1, 高度为min(h[l], h[i]) - h[top]
         * 根据宽度和高度即可计算得到该区域能接的水的量 
         * 为了得到left，将top出栈，对top能接的水量之后,left变成新的top，重复直到栈空
         * 或栈顶下标元素大于等于h[i],i入栈，继续遍历
         * 边遍历边统计蓄水量
         */
        int sum = 0;
        int n = height.size();
        stack<int> stk;

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty())
                /* 没有left */
                    break;
                int left = stk.top();
                int curwidth = i - left - 1;
                int curheight = min(height[left], height[i]) - height[top];
                sum += curheight * curwidth;
            }
            stk.push(i);
        }
        
        return sum;
    }
};


class Solution {
public:
    void dump(vector<int> &arr) {
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int trap(vector<int>& height) {
        /*
         * 动态规划
         * i处能水能达到的最大高度为向左和向右的最大高度的最小值
         * i处能接的水量为i处水能达到的最大高度减去i的高度height[i]
         * 从左到右遍历计算leftmax[i] = max(leftmax[i - 1], height[i])
         * 从右向左遍历计算rightmax[i] = max(rightmax[i + 1], height[i])
         * 遍历统计 sum: {min(leftmax[i], rightmax[i]) - height[i]}
         */
        int n = height.size();
        if (n == 0)
            return 0;
        vector<int> leftmax(n);
        vector<int> rightmax(n);

        leftmax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftmax[i] = max(leftmax[i - 1], height[i]);
        }

        rightmax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightmax[i] = max(rightmax[i + 1], height[i]);
        }

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += min(leftmax[i], rightmax[i]) - height[i];

        return sum;
    }
};
