
class Solution {
public:
    /*
     * 数组cnt记录每个字母出现的次数
     * 依次从左向右，从右向左填充
     */    
    string sortString(string s) {
        string res;
        int cnt[26] = {};
        int len = s.length(), i;
        bool flag = true;

        for (auto &c : s) cnt[c - 'a']++;

        while (res.length() != len) {
            if (flag) {
                for (i = 0; i < 26; i++) {
                    if (cnt[i]) {
                        cnt[i]--;
                        res.push_back(i + 'a');
                    }
                }
            } else {
                for (i = 25; i >= 0; i--) {
                    if (cnt[i]) {
                        cnt[i]--;
                        res.push_back(i + 'a');
                    }
                }
            }
            flag = !flag;
        }

        return res;
    }
};

class Solution {
public:
    string sortString(string s) {
        string res;
        /* true -> 小到大，false大到小 */
        bool flag = true;

        /* 从小到打排列 */
        sort(s.begin(), s.end());

        while(!s.empty()) {
            //cout << s << " " << flag << endl;
            if (flag) {
                res.push_back(s[0]);
                s.erase(s.begin() + 0);
                for (int i = 0; i < s.length(); i++) {
                    //cout << s[i] << "-" << res.back() << endl;
                    if (s[i] == res.back())
                        continue;
                    res.push_back(s[i]);
                    s.erase(s.begin() + i);
                    i--;
                }
                //cout << s << "---" << res << endl;
            } else {
                res.push_back(s[s.length() - 1]);
                s.pop_back();
                for (int i = s.length() - 1; i >= 0; i--) {
                    //cout << s[i] << "--" << res.back() << endl;
                    if (s[i] == res.back())
                        continue;
                    res.push_back(s[i]);
                    s.erase(s.begin() + i);
                }
                //cout << s << "----" << res << endl;
            }
            flag = !flag;
        }

        return res;
    }
};
