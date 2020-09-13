

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1;

        if (nums.size() == 0)
            return 0;

        /* 双指针 */
        while (j < nums.size()) {
            while (j < nums.size() && nums[j] == nums[i])
                j++;
            if (j == nums.size())
                break;
            i++;
            nums[i] = nums[j];
        }

        return i + 1;
    }
};



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                nums.erase(nums.begin() + i);
                i--;
            }
        }

        return nums.size();
    }
};
