
class Solution {
public:
    bool isletter(char c) {
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    }

    void swap(string &s, int i, int j) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }

    string reverseOnlyLetters(string S) {
        /* 双指针 */
        int l = 0, r = S.length() - 1;

        while (l < r) {
            if (!isletter(S[l])) {
                l++;
                continue;
            }
            if (!isletter(S[r])) {
                r--;
                continue;
            }
            //cout << S << " " << l << " " << r << endl;
            swap(S, l, r);
            l++;
            r--;
        }

        return S;
    }
};
