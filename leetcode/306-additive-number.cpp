


class Solution {
public:
    string addstring(string &n1, string &n2) {
        /* 加法模拟 */
        string res;
        int car = 0;
        int i = n1.length() - 1;
        int j = n2.length() - 1;

        while (i >= 0 || j >= 0 || car == 1) {
            int sum = car;

            if (i >= 0) {
                sum += n1[i] - '0';
                i--;
            }

            if (j >= 0) {
                sum += n2[j] - '0';
                j--;
            }

            if (sum >= 10) {
                car = 1;
                sum -= 10;
            } else {
                car = 0;
            }
            res.insert(res.begin(), sum + '0');
        }

        //cout << n1 << " + " << n2 << " = " << res << endl;
        return res;
    }

    bool dfs(string &num, int i, int j, int k) {
        if ((num[i] == '0' && j - i > 1) || (num[j] == '0' && k - j > 1))
        /* 前导0 - 剪枝 */
            return false;

        string n1 = num.substr(i, j - i);
        string n2 = num.substr(j, k - j);
        string sum = addstring(n1, n2);
        int n = sum.length();
        //cout << i << "-" << j << "-" << k << ": " << n1 << " " << n2 << " " << sum << " " << n << endl;

        if (k + n > num.size() || sum != num.substr(k, n))
        /* 下一个数不满足累加数 - 剪枝 */
            return false;

        if (k + n == num.size())
            return true;

        return dfs(num, j, k, k + n);
    }

    bool isAdditiveNumber(string num) {
        int n = num.size();
        if (n < 3)
            return false;

        /*
         * 回溯算法
         * 固定前2个数之后，后面一个数也是固定的，如果接下来的数符合条件，继续检查。如果不符合，则剪枝
         * 如果数字有前缀0，减枝。直到处理完毕，则返回true
         */
        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (dfs(num, 0, i, j))
                    return true;
            }
        }

        return false;
    }
};
