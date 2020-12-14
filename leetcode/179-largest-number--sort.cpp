


bool compare (int &a, int &b) {
    /* 哪个在前拼接结果大，哪个就大 */
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        /* 排序 */
        sort(nums.begin(), nums.end(), compare);

        /* 构建结果 */
        for (auto &num : nums) {
            res += to_string(num);
        }

        /* 最高位为0则返回0 */
        return res[0] == '0' ? "0" : res;
    }
};
