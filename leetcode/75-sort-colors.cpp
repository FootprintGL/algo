
class Solution {
public:
    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    void sortColors(vector<int>& nums) {
        /* 双指针 */
        int p0 = 0, p2 = nums.size() - 1;
        int i = 0;

        while (i <= p2) {
            if (nums[i] == 0) {
                swap(nums, i, p0);
                i++;
                p0++;
            } else if (nums[i] == 1) {
                i++;
            } else {
                swap(nums, i, p2);
                /* p2位置可能为2，不需要更新i */
                p2--;
                
            }
        }
    }
};


class Solution {
public:
    void sortColors(vector<int>& nums) {
        /* 统计0，1，2的个数进行重排 */
        int n = nums.size(), i;
        int c0 = 0, c1 = 0, c2 = 0;

        /* 统计0，1，2的个数 */
        for (i = 0; i < n; i++) {
            if (nums[i] == 0)
                c0++;
            else if (nums[i] == 1)
                c1++;
            else
                c2++;
        }

        //cout << c0 << " " << c1 << " " << c2 << endl;
        int j = 0;
        i = 0;
        while (i < c0) {
            nums[j++] = 0;
            i++;
        }
        i = 0;
        while (i < c1) {
            nums[j++] = 1;
            i++;
        }
        i = 0;
        while (i < c2) {
            nums[j++] = 2;
            i++;
        }
    }
};
