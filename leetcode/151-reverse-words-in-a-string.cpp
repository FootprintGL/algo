

class Solution {
public:
    /* 翻转字符串 */
    void reverse(string &s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            char c = s[l];
            s[l] = s[r];
            s[r] = c;
            l++;
            r--;
        }
    }

    string reverseWords(string s) {
        string res;

        /*
         * 实现
         * 先提取单词并放入数组
         * 从后往前遍历数组构建结果
         */
        vector<string> vec;
        string temp;

        /* 提取单词 */
        istringstream iss(s);
        while (iss >> temp)
            /* 默认的delim也是' ' */
            vec.push_back(temp);

        /* 反转单词
        for (auto &word : vec)
            reverse(word);
        */

        /* 构建结果 */
        for (int i = vec.size() - 1; i >= 0; i--) {
            res += vec[i];
            if (i != 0)
                res += ' ';
        }

        return res;
    }
};
