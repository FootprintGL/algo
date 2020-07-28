
class Solution {
public:
    /* 哈希表 */
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mymap;
        int n = nums.size();
        int cnt = 0, res;

        for (auto num : nums) {
            mymap[num]++;
            if (mymap[num] > cnt) {
                cnt = mymap[num];
                res = num;
            }
        }

        return res;
    }
};



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1;

        sort(nums.begin(), nums.end());
        int res = nums[0];
        int i = 1;
        while (i < n) {
            while (i < n && nums[i] == res) {
                cnt++;
                if (cnt > n / 2)
                    return res;
                i++;
            }
            if (i < n) {
                res = nums[i];
                i++;
                cnt = 1;
            }
        }

        return res;
    }
};
