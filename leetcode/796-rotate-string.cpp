
class Solution {
public:
    bool rotateString(string A, string B) {
        int m = A.length(), n = B.length();

        return (m == n && (A + A).find(B) != string::npos);
    }
};



class Solution {
public:
    bool rotateString(string A, string B) {
        int m = A.length(), n = B.length();

        if (m != n)
            return false;

        if (m == 0 && n == 0)
            return true;

        for (int i = m - 1; i >= 1; i--) {
            if (B.substr(i, m - i) == A.substr(0, m - i) && B.substr(0, i - 1) == A.substr(m - i, i - 1))
                return true;
        }

        return false;
    }
};
