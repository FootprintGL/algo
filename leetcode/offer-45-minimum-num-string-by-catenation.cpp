

bool compare(const string &a, const string &b) {
    /* "30" + "3" < "3" + "30" -> "30" < "3" */
    return a + b < b + a;
}

class Solution {

public:
    string minNumber(vector<int>& nums) {
        string res;
        vector<string> strs;

        /* 数字转换成字符串 */
        for (auto &num : nums)
            strs.push_back(to_string(num));

        /* 排序 */
        sort(strs.begin(), strs.end(), compare);

        /* 构建结果 */
        for (auto &str : strs)
            res += str;

        return res;
    }
};
