
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.length();
        int len2 = version2.length();
        int idx1 = 0, idx2 = 0;

        while (idx1 < len1 || idx2 < len2) {
            if (idx1 < len1 && version1[idx1] == '.')
                idx1++;

            if (idx2 < len2 && version2[idx2] == '.')
                idx2++;
            
            /* 新段开始 - 计算段内数据并比较大小 */
            int cur1 = 0;
            int cur2 = 0;
            while (idx1 < len1 && version1[idx1] != '.')
                cur1 = cur1 * 10 + version1[idx1++] - '0';
            while (idx2 < len2 && version2[idx2] != '.')
                cur2 = cur2 * 10 + version2[idx2++] - '0';
            
            if (cur1 != cur2)
                return cur1 > cur2 ? 1 : -1;
        }

        return 0;
    }
};


class Solution {
public:
    int compareVersion(string version1, string version2) {
        /* istringstream分割 */
        vector<string> v1;
        vector<string> v2;

        istringstream iss1(version1);
        string buf;

        while (getline(iss1, buf, '.')) {
            v1.push_back(buf);
        }

        istringstream iss2(version2);
        while (getline(iss2, buf, '.'))
            v2.push_back(buf);

        int start = 0;
        int size1 = v1.size();
        int size2 = v2.size();
        /* 逐个比较 */
        while (start < max(size1, size2)) {
            if (start < size1 && start < size2) {
                if (stoi(v1[start]) < stoi(v2[start]))
                    return -1;
                else if (stoi(v1[start]) > stoi(v2[start]))
                    return 1;
            } else if (start < size1) {
                if (stoi(v1[start]) > 0)
                    return 1;
            } else if (start < size2) {
                if (stoi(v2[start]) > 0)
                    return -1;
            }
            start++;
        }

        return 0;
    }
};
