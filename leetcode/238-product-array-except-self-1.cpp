class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {        
        vector<int> left (nums.size(), -1);
        vector<int> right (nums.size(), -1);
        vector<int> res (nums.size(), -1);
        int i, pre = 1, post = 1;
        
        /*
        * 直观的想法是计算数组内所有元素的成绩total = nums[0] * ... * nums[n - 1]
        * res[i]则为total/nums[i]，如果有元素为0则算法失效，但题目要求不能用除法。
	* i把数组分成两段，res[i]是这两段的乘积。开辟两个数组left和right，left存放
	* 前缀乘积（从左向右)，right存放后缀乘积（从右向左)
        * res[i] = left[i - 1] * right[i + 1]
        */
        for (i = 0; i < nums.size(); i++) {
            pre *= nums[i];
            post *= nums[nums.size() - i - 1];
            left[i] = pre;
            right[nums.size() - i - 1] = post;
        }
/*
        for (i = 0; i < nums.size(); i++)
            cout << left[i] << " ";
        cout << endl;

        for (i = 0; i < nums.size(); i++)
            cout << right[i] << " ";
        cout << endl;
*/
        res[0] = right[1];
        res[nums.size() - 1] = left[nums.size() - 2];
        for (i = 1; i < nums.size() - 1; i++) {
            res[i] = left[i - 1] * right[i + 1];
        }

        return res;
    }
};
