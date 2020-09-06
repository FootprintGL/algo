
class Solution {
public:
    string makeGood(string s) {
        string ans;
        int dis = 'a' - 'A';

        /* 堆栈 */
        for (auto c : s) {
            if (!ans.empty() && abs(ans.back() - c) == dis)
                ans.pop_back();
            else
                ans.push_back(c);
        }

        return ans;
    }
};


class Solution {
public:
    string makeGood(string s) {
        int n = s.length();

        if (n == 1)
            return s;

        int l = 0, dis = 'a' - 'A';

        while (l < s.length() - 1) {
            //cout << s << " " << l << endl;
            if (abs(s[l] - s[l + 1]) == dis) {
                s.erase(l, 2);

                if (s.empty())
                    break;

                //cout << s << " - " << l << endl;
                if (l > 0) {
                    /* 删除2个字母，注意偏移，这时length也变了 */
                    l--;
                }
            } else {
                l++;
            }
        }

        //cout << s << endl;
        return s;
    }
};
