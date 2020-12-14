


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        /*
         * 单调栈 - 同496类似
         * 将nums2中元素求出下一个更大的元素，并放入哈希表，再遍历nums1直接找出答案
         * 循环数组需要两次遍历
         * 有重复元素，需要保持index到哈希表
         */
        int n = nums.size(), i;
        vector<int> res(n, -1);
        stack<int> st;
        unordered_map<int, int> tbl;

        for (i = 0; i < n; i++) {
            /* 第一次遍历搜索 */
            while (!st.empty() && nums[st.top()] < nums[i]) {
                tbl[st.top()] = i;
                st.pop();
            }
            /* 栈为空或栈中元素均大于num，入栈 */
            st.push(i);
        }

        for (i = 0; i < n; i++) {
            /* 从头开始第二次遍历搜索 */
            while (!st.empty() && nums[st.top()] < nums[i]) {
                tbl[st.top()] = i;
                st.pop();
            }
        }

        while (!st.empty()) {
            /* 栈中的元素后面没有更大元素 */
            tbl[st.top()] = -1;
            st.pop();
        }

        /* 构建结果 */
        for (int i = 0; i < n; i++) {
            res[i] = tbl[i] != -1 ? nums[tbl[i]] : -1;
        }

        return res;
    }
};
