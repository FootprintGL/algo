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
