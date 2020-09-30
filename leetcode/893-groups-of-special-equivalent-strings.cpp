

class Solution {
public:
    string mysort(string &s) {
        string odd, even, res;

        /* 提取奇数位和偶数位 */
        for (int i = 0; i < s.length(); i++) {
            if (i % 2)
                odd += s[i];
            else
                even += s[i];
        }
        /* 排序奇数位和偶数位 */
        //cout << odd << " " << even << endl;
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        //cout << odd << " - " << even << endl;
        /* 根据排序好奇数位和偶数为字符串构建结果 */
        int l = 0, r = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i % 2)
                res += odd[l++];
            else
                res += even[r++];
        }

        //cout << s << " " << res << endl << endl;
        return res;
    }

    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> tbl;

        for (auto &s : A)
            tbl.insert(mysort(s));

        return tbl.size();
    }
};
