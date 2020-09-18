

class Solution {
public:
    /* email地址翻译 - 本地名称需要去掉‘.‘和’+’后面的字符 */
    void translate(string &email) {
        int l = 0, r = 0;
        int n = email.length();
        string local;
        bool ignore = false;

        while (r < n) {
            while (r < n && email[r] != '@') {
                if (email[r] == '.') {
                    r++;
                    continue;
                }
                if (email[r] == '+') {
                    r++;
                    ignore = true;
                    continue;
                }
                if (!ignore)
                    local += email[r];
                r++;
            }
            email = local + email.substr(r, n - r);
            //cout << email << endl;
            break;
        }
    }

    int numUniqueEmails(vector<string>& emails) {

        unordered_set<string> tbl;

        for (auto &email : emails) {
            translate(email);
            tbl.insert(email);
        }

        return tbl.size();
    }
};
