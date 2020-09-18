

class Solution {
public:
    bool digit(char c) {
        return c >= '0' && c <= '9';
    }

    char toupper(char c) {
        char ans = c;
        if (c >= 'a' && c <= 'z')
            ans = c - 32;
        //cout << c << " " << ans << endl;
        return ans;
    }

    string licenseKeyFormatting(string S, int K) {
        string res;

        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '-') {
                S.erase(S.begin() + i);
                i--;
                continue;
            }

            if (!digit(S[i]))
                S[i] = toupper(S[i]);
        }
        //cout << S << endl;

        int cnt = 0;
        for (int i = S.length() - 1; i >= 0; i--) {
            res.insert(res.begin(), S[i]);
            cnt++;
            if (i != 0 && cnt == K) {
                res.insert(res.begin(), '-');
                cnt = 0;
            }
        }

        return res;
    }
};
