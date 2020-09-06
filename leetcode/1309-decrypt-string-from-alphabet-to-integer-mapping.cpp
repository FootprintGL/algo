


class Solution {
public:
    string freqAlphabets(string s) {
        string ans;
        int i = s.length() - 1;
        int tmp;

        while (i >= 0) {
            if (s[i] == '#') {
                tmp = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
                ans.insert(ans.begin(), 'j' + tmp - 10);
                i = i - 3;
            } else {
                ans.insert(ans.begin(), s[i] - '1' + 'a');
                i--;
            }
        }

        return ans;
    }
};
