

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> mymap;

        /* 哈希表 */
        if (nums1.size() <= nums2.size()) {
            for (auto x : nums1)
                ++mymap[x];
            for (auto x : nums2) {
                if (mymap.count(x)) {
                    res.push_back(x);
                    mymap[x]--;
                    if (mymap[x] == 0)
                        mymap.erase(x);
                }
            }
        } else {
            for (auto x : nums2)
                ++mymap[x];
            for (auto x : nums1) {
                if (mymap.count(x)) {
                    res.push_back(x);
                    mymap[x]--;
                    if (mymap[x] == 0)
                        mymap.erase(x);
                }
            }
        }

        return res;
    }
};


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int len1 = nums1.size();
        int len2 = nums2.size();

        if (len1 == 0 || len2 == 0)
            return res;
        
        /* 排序 */
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        /* 双指针 */
        int i = 0, j = 0;
        while (i < len1 && j < len2) {
            while (i < len1 && nums1[i] < nums2[j])
                i++;
            
            if (i == len1)
                break;

            if (nums1[i] == nums2[j]) {
                /* 找到一个相同元素，从下一个元素继续处理 */
                res.push_back(nums1[i]);
                i++;
                j++;
                continue;
            }

            while (j < len2 && nums1[i] > nums2[j])
                j++;

            if (j == len2)
                break;

            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        return res;
    }
};
