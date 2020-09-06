
class Solution {
public:
    bool isPalindrome(string s) {
        cout << s << endl;
        int l = 0, r = s.length() - 1;
        while (l <= r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int l = 0, r = s.length() - 1;

        while (l <= r) {
            if (s[l] != s[r]) {
                return isPalindrome(s.substr(l, r - l)) || isPalindrome(s.substr(l + 1, r - l));
            }

            l++;
            r--;
        }

        return true;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        cout << s << endl;
        int l = 0, r = s.length() - 1;
        while (l <= r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int l = 0, r = s.length() - 1;

        while (l <= r) {
            //cout << l << " " << r << " " << s[l] << " " << s[r] << endl;
            if (s[l] != s[r]) {
                if (r == l + 1) {
                    return true;
                } else {
                    /* 尝试删除一个字符 */
                    if (s[l] == s[r - 1] && isPalindrome(s.substr(l, r - l)))
                        return true;
                    if (s[l + 1] == s[r] && isPalindrome(s.substr(l + 1, r - l)))
                        return true;

                    return false;
                }
            }

            l++;
            r--;
        }

        return true;
    }
};
