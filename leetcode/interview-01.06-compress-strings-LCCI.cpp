
class Solution {
public:
    string compressString(string S) {
        string res;
        int n = S.length();

        if (n < 3)
            return S;

        char cur = S[0];
        int cnt = 1;

        for (int i = 1; i < n; i++) {
            if (S[i] == cur) {
                cnt++;
            } else {
                res += cur + to_string(cnt);
                cur = S[i];
                cnt = 1;
            }
        }
        res += cur + to_string(cnt);

        return res.length() < n ? res : S;
    }
};

class Solution {
public:
    string compressString(string S) {
        /* 双指针 */
        string res;
        int n = S.length();
        int l = 0, r = l + 1;

        if (n < 3)
            return S;

        while (r < n) {
            r = l + 1;
            while (r < n && S[r] == S[l])
                r++;

            //cout << l << " " << r << endl;
            /* 找到新的单词 */
            res.push_back(S[l]);
            res += to_string( r - l);

            l = r;
        }

        return res.length() < n ? res : S;
    }
};
