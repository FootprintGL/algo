
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;

        /* s2 + s2必然包含s1 */
        return (s2 + s2).find(s1) != string::npos;
    }
};
