

bool digit(string s) {
    return (s[0] >= '0' && s[0] <= '9');
}

bool comp(string s1, string s2) {
    string key1, key2;
    string content1, content2;
    int keyend = 0;

    /* 提取s1的标记和内容 */
    while (keyend < s1.length() && s1[keyend] != ' ')
        keyend++;
    key1 = s1.substr(0, keyend);
    content1 = s1.substr(keyend + 1, s1.length() - keyend - 1);

    /* 不需要剔除空格
    while (keyend++ < s1.length())
        if (s1[keyend] != ' ')
            content1 += s1[keyend];
        */

    /* 提取s2的标记和内容 */
    keyend = 0;
    while (keyend < s2.length() && s2[keyend] != ' ')
        keyend++;
    key2 = s2.substr(0, keyend);
    content2 = s2.substr(keyend + 1, s2.length() - keyend - 1);
    /* 不需要剔除空格
    while (keyend++ < s2.length())
        if (s2[keyend] != ' ')
            content2 += s2[keyend];
            */

    /* 比较 */
    if (digit(content1) && digit(content2)) {
        return false;
    } else if (!digit(content1) && digit(content2)) {
        return true;
    } else if (digit(content1) && !digit(content2)) {
        return false;
    } else {
        return content1 == content2 ? key1 < key2 : content1 < content2;
    }
}
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        /* stable_sort来保证数字元素位置不变 */
        stable_sort(logs.begin(), logs.end(), comp);
        return logs;
    }
};
