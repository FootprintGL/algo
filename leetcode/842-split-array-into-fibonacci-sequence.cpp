

class Solution {
public:
    vector<int> res;
    int len;

    bool dfs(string &s, int start, int p1, int p2) {
        /*
        cout << start << " " << p1 << " " << p2 << endl;
        cout << "dump res: ";
        for (auto &t : res)
            cout << t << " ";
        cout << endl;
        */

        if (start == len) {
            return res.size() > 2;
        }

        long lcur = 0;
        for (int i = start; i < len; i++) {
            if (i > start && s[start] == '0')
                /* 不能有前导0 */
                break;
            lcur = lcur * 10 + s[i] - '0';
            if (lcur > INT_MAX)
                /* 整数溢出 */
                break;
            if (res.size() >= 2) {
                if (lcur < (long)p1 + (long)p2)
                    continue;
                else if (lcur > (long)p1 + (long)p2)
                    break;
            }
            res.push_back(lcur);
            if (dfs(s, i + 1, p2, lcur))
                return true;
            /* 回溯 */
            res.pop_back();
        }

        return false;
    }

    vector<int> splitIntoFibonacci(string S) {
        len = S.length();
        dfs(S, 0, 0, 0);
        return res;
    }
};
