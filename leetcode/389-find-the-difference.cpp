

class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;

        /* 相同的字母异或为0，新加的字母单数个，可以通过异或找出 */
        for (int i = 0; i < s.length(); i++) {
            ans ^= s[i];
            ans ^= t[i];
        }
        ans ^= t[t.length() - 1];

        return ans;
    }
};
