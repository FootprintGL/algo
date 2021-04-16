

class Solution {
public:
    complex<int> helper(string s) {
        /* 提取虚部和实部 */
        int a = 0, b = 0;
        int i = 0, j = 0;
        /* 标记是否为负数 */
        bool flag = false;

        /* 提取实数部分 */
        if (s[i] == '-') {
            flag = true;
            i++;
            j++;
        }
        while (s[j] >= '0' && s[j] <= '9')
            j++;
        //cout << i << " " << j << " " << s.substr(i, j - i) << endl;
        a = stoi(s.substr(i, j - i));
        if (flag)
            a = -a;

        /* 跳过+号 */
        j++;
        i = j;
        /* 提取虚数部分 */
        flag = false;
        if (s[i] == '-') {
            flag = true;
            i++;
            j++;
        }
        while (s[j] >= '0' && s[j] <= '9')
            j++;
        //cout << i << " " << j << " " << s.substr(i, j - i) << endl;
        b = stoi(s.substr(i, j - i));
        if (flag)
            b = -b;

        //cout << a << " " << b << endl;
        return complex<int>{a, b};
    }

    string complexNumberMultiply(string a, string b) {
        /*
         * (a + i * b) * (x + i * y) = ax - by + i * (bx + ay)
         * 分别提取实部和虚部再计算
         */
        auto t = helper(a) * helper(b);

        return to_string(t.real()) + '+' + to_string(t.imag()) + 'i';
    }
};

class Solution {
public:
    vector<int> helper(string s) {
        /* 提取虚部和实部 */
        int a = 0, b = 0;
        int i = 0, j = 0;
        /* 标记是否为负数 */
        bool flag = false;

        /* 提取实数部分 */
        if (s[i] == '-') {
            flag = true;
            i++;
            j++;
        }
        while (s[j] >= '0' && s[j] <= '9')
            j++;
        //cout << i << " " << j << " " << s.substr(i, j - i) << endl;
        a = stoi(s.substr(i, j - i));
        if (flag)
            a = -a;

        /* 跳过+号 */
        j++;
        i = j;
        /* 提取虚数部分 */
        flag = false;
        if (s[i] == '-') {
            flag = true;
            i++;
            j++;
        }
        while (s[j] >= '0' && s[j] <= '9')
            j++;
        //cout << i << " " << j << " " << s.substr(i, j - i) << endl;
        b = stoi(s.substr(i, j - i));
        if (flag)
            b = -b;

        //cout << a << " " << b << endl;
        return {a, b};
    }

    string complexNumberMultiply(string a, string b) {
        /*
         * (a + i * b) * (x + i * y) = ax - by + i * (bx + ay)
         * 分别提取实部和虚部再计算
         */
        string res;
        vector<int> t1 = helper(a);
        vector<int> t2 = helper(b);

        int c = t1[0] * t2[0] - t1[1] * t2[1];
        int d = t1[0] * t2[1] + t1[1] * t2[0];
        res = to_string(c) + '+' + to_string(d) + 'i';

        return res;
    }
};
