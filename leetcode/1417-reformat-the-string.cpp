
class Solution {
public:
    string reformat(string s) {

        int len = s.length();
        string res;
        int lcnt = 0, dcnt = 0;

        /* 统计字母和数字个数 */
        for (auto c : s) {
            if (c >= '0' && c <= '9')
                dcnt++;
            else
                lcnt++;
        }

        //cout << lcnt << " " << dcnt << endl;
        if (abs(lcnt - dcnt) > 1)
            return "";

        /* 多的放奇数位，少的放偶数位 */
        int lidx = 0, didx = 1, i;
        if (lcnt < dcnt) {
            didx = 0;
            lidx = 1;
        }

        res.resize(len);
        for (int i = 0; i < len; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                res[didx] = s[i];
                didx += 2;
            } else {
                res[lidx] = s[i];
                lidx += 2;
            }
        }

        return res;
    }
};
