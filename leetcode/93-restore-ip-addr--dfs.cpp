


class Solution {
    vector<string> res;
    vector<int> segments;
public:
    void helper(string &s, int start, int segid) {

        if (segid == 4) {
            string ipaddr;
            if (start == s.size()) {
                for (int i = 0; i < 4; i++) {
                    ipaddr += to_string(segments[i]);
                    if (i != 3)
                        ipaddr += ".";
                }
                cout << ipaddr << endl;
                res.push_back(ipaddr);
            }
            return;
        }

        /* 没找到4段ip地址字符串已遍历完 */
        if (start == s.size())
            return;

        /* 不存在前缀0，如果start为0，则该段为0 */
        if (s[start] == '0') {
            segments[segid] = 0;
            return helper(s, start + 1, segid + 1);
        }

        /* 一般情况 */
        int addr = 0;
        for (int i = start; i < s.size(); i++) {
            addr = addr * 10 + (s[i] - '0');
            if (addr > 0 && addr <= 255) {
                segments[segid] = addr;
                helper(s, i + 1, segid + 1);
            } else {
                break;
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        segments.resize(4);
        helper(s, 0, 0);
        return res;
    }
};
