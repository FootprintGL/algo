

class Solution {
public:
    int findString(vector<string>& words, string s) {
        int n = words.size();
        int l = 0, r = n - 1, m, tmp;

        while (l <= r) {
            /* 跳过左边空串 */
            while (l < r && words[l] == "")
                l++;
            /* 跳过右边空串 */
            while (r > l && words[r] == "")
                r--;
            if (l <= r) {
                m = l + (r - l) / 2;
                tmp = m;
                /* m处为空串，向左跳过空传 */
                while (m > l && words[m] == "")
                    m--;
                if (words[m] > s) {
                    /* 在新m左边 */
                    r = m - 1;
                } else if (words[m] < s) {
                    /* 原m右边 */
                    l = tmp + 1;
                    //l = m + 1;
                } else {
                    return m;
                }
            }
        }

        return -1;
    }
};




class Solution {
public:
    int findString(vector<string>& words, string s) {
        /* 双指针 */
        int l = 0, r = 0;
        int n = words.size();
        bool find = false;

        while (r < n) {
            if (r < n && words[r] == "") {
                r++;
                continue;
            }

            //cout << s << " " << words[r] << endl;
            //if (s.compare(words[r]) == 0) {
            if (s == words[r]) {
                find = true;
                break;
            }

            //l++;
            r++;
        }

        return find ? r : -1;
    }
};
