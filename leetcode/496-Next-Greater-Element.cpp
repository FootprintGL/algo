
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        /*
         * 单调栈
         * 将nums2中元素求出下一个更大的元素，并放入哈希表，再遍历nums1直接找出答案
         */
        vector<int> res(nums1.size(), -1);
        stack<int> st;
        unordered_map<int, int> tbl;

        for (auto &num : nums2) {
            while (!st.empty() && st.top() < num) {
                /* 弹出比num小的数 */
                tbl[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        while (!st.empty()) {
            /* 栈里剩下的数后面没有更大的数 */
            tbl[st.top()] = -1;
            st.pop();
        }

        for (int i = 0; i < nums1.size(); i++) {
            res[i] = tbl[nums1[i]];
        }

        return res;
    }
};


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> *res = new vector<int>(len1, -1);
        int i, j, k;
        int find = 0;
        /* 暴力循环 */
        for (i = 0; i < len1; i++) {
            for (j = 0; j < len2; j++) {
                if (nums1[i] == nums2[j]) {
                    find = 1;
                    for (k = j + 1; k < len2; k++) {
                        if (nums1[i] < nums2[k]) {
                            res->at(i) = nums2[k];
                            break;
                        }
                    }
                }
                if (find) {
                    find = 0;
                    break;
                }
            }
        }

        return *res;
    }
};
