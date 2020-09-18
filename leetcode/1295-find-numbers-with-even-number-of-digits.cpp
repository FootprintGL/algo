

class Solution {
public:
    /* 判断位数是否是偶数 */
    bool helper(int num) {
        int cnt = 0;

        while (num) {
            cnt++;
            num /= 10;
        }

        return cnt % 2 ? false : true;
    }

    int findNumbers(vector<int>& nums) {
        int cnt = 0;

        for (auto &num : nums)
            if (helper(num))
                cnt++;

        return cnt;
    }
};
