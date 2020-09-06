
class Solution {
public:
    string reverseword(string s) {
        //cout << s << endl;
        int len = s.length();

        if (len == 1)
            return s;

        int i = 0, j = len - 1;
        while (i <= j) {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;
            j--;
        }

        //cout << s << endl << endl;

        return s;
    }

    string reverseWords(string s) {
        int len = s.length();

        if (len <= 1)
            return s;

        int start = 0, end = 1;
        string str;

        for (end = 0; end < len; end++) {
            if (s[end] != ' ')
                continue;
            str = reverseword(s.substr(start, end - start));
            s.replace(start, end - start, str);
            start = end + 1;
        }
        str = reverseword(s.substr(start, end - start + 1));
        s.replace(start, end - start + 1, str);

        return s;
    }
};
