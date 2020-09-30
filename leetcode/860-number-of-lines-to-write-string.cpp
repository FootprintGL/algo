
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        /* 模拟 - 大于100时换行 */
        vector<int> res(2, 0);
        int row = 1, rem = 0;

        for (auto &c : S) {
            if (rem + widths[c - 'a'] > 100) {
                row++;
                rem = widths[c - 'a'];
            } else {
                rem += widths[c - 'a'];
            }
        }

        res[0] = row;
        res[1] = rem;

        return res;
    }
};



/* 下面解法是错误的，因为最后的位置可能出现放不下一个字符的情况 */
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        /* 先统计需要写多少个字符，在算总行数和最后一行字符数 */
        vector<int> res(2, 0);
        int cnt = 0;

        for (auto &c : S) {
            cnt += widths[c - 'a'];
        }

        int row = cnt / 100;
        int rem = cnt % 100;

        if (rem)
            row++;

        res[0] = row;
        res[1] = rem;

        return res;
    }
};
