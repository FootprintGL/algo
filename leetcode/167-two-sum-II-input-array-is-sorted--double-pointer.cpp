class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res (2, 0);
        int n = numbers.size();
        int i, j;

        i = 0;
        j = n - 1;
        /* 
         * 双指针
         * 初始化i, j分别指向数组首尾元素
         * 如果numbers[i] + numbers[j] > target，向左移动j使两元素和变小
         * 如果numbers[i] + numbers[j] < target，向右移动i使两元素和变大
         * 直到找到numbers[i] + numbers[j] < target,返回结果
         * 题目明确只有一对答案，所以肯定能找到
         */
        while (true) {
            while (j > i && numbers[i] + numbers[j] > target)
                j--;
            if (numbers[i] + numbers[j] == target) {
                res[0] = i + 1;
                res[1] = j + 1;
                break;
            }
            while (i < j && numbers[i] + numbers[j] < target)
                i++;
            if (numbers[i] + numbers[j] == target) {
                res[0] = i + 1;
                res[1] = j + 1;
                break;
            }
        }

        return res;
    }
};
