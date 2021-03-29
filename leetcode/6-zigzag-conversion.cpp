

class Solution {
public:
    string convert(string s, int numRows) {
        /*
         * 模拟
         * 排列规则为0,1,2,...,numRows - 1, numRows - 2, ..., 0, 1, 2...
         * 每一行单独放置，最后再拼出结果
         */

        if (numRows == 1)
        /* 特殊情况 - 只有一行 */
            return s;

        int n = s.length();
        vector<string> vec(min(numRows, n));
        int row = 0;
        bool up2low = false;

        /* 按行分别放入相应的行 */
        for (auto &c : s) {
            //cout << row << endl;
            vec[row] += c;
            if (row == 0 || row == numRows - 1)
                up2low = !up2low;
            row += up2low ? 1 : -1;
        }

        /* 构建结果 */
        string res;
        for (auto &s : vec) {
            //cout << s << endl;
            res += s;
        }

        return res;
    }
};


class Solution {
public:
    string convert(string s, int numRows) {
        /*
         * 模拟
         * 排列规则为0,1,2,...,numRows - 1, numRows - 2, ..., 0, 1, 2...
         * 每一行单独放置，最后再拼出结果
         */

        if (numRows == 1)
        /* 特殊情况 - 只有一行 */
            return s;

        vector<string> vec(numRows);
        int row = 0;
        bool up2low = true;

        /* 按行分别放入相应的行 */
        for (auto &c : s) {
            cout << row << endl;
            if (up2low) {
                vec[row] += c;
                row++;
                if (row == numRows) {
                    row -= 2;
                    up2low = false;
                }
            } else {
                vec[row] += c;
                row--;
                if (row < 0) {
                    row += 2;
                    up2low = true;
                }
            }
        }

        /* 构建结果 */
        string res;
        for (auto &s : vec) {
            cout << s << endl;
            res += s;
        }

        return res;
    }
};
