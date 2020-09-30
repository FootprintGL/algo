

class Solution {
public:
    bool vowel(char c) {
        return (c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i' ||
            c == 'A' || c == 'E' || c == 'O' || c == 'U' || c == 'I');
    }

    string reverseVowels(string s) {
        /* 双指针 */
        if (s.length() < 2)
            return s;

        int l = 0;
        int r = s.length() - 1;

        while (l <= r) {
            while (l < r && !vowel(s[l]))
                l++;

            while (l < r && !vowel(s[r]))
                r--;

            char t = s[l];
            s[l] = s[r];
            s[r] = t;
            l++;
            r--;
        }

        return s;
    }
};
