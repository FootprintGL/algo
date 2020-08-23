class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int i = num1.length() - 1, j = num2.length() - 1, res, carry = 0;
        int x, y;

        while (i >= 0 || j >= 0 || carry) {
            x = i >= 0 ? num1[i] - '0' : 0;
            y = j >= 0 ? num2[j] - '0' : 0;
            res = x + y + carry;
            ans.insert(ans.begin(), res % 10 + '0');
            carry = res / 10;
            i--;
            j--;
        }

        return ans;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        
        string ans, ans1;
        int i = num1.length() - 1, j = num2.length() - 1, k;
        int carry = 0, res, f;

        f = 0;
        for (i = num1.length() - 1; i >= 0; i--) {
            ans1 = "";
            carry = 0;
            for (j = num2.length() - 1; j >= 0; j--) {
                res = (num1[i] - '0') * (num2[j] - '0') + carry;
                ans1.insert(ans1.begin(), res % 10 + '0');
                carry = res / 10;
            }
            /* 进位处理 */
            if (carry)
                ans1.insert(ans1.begin(), carry + '0');
            /* 竖式位置偏移 */
            for (k = 0; k < f; k++)
                ans1.push_back('0');
            f++;
            /* 累加结果 */
            ans = addStrings(ans, ans1);
        }
        
        return ans;
    }
};

/* 
 * 执行出错 
 * "123456789"
 * "987654321"
 * int type data overflow
 */
class Solution {
public:
    int multi(char a, char b, int &c) {
        int ai = a - '0';
        int bi = b - '0';
        int res;

        res = ai * bi + c;
        if (res >= 10) {
            c = res / 10;
            res %= 10;
        } else {
            c = 0;
        }
        cout << "multi: " << c << " " << res << endl;

        return res;
    }

    string convert(int num) {
        string res;
        int tmp;

        while (num) {
            tmp = num % 10;
            res.insert(res.begin(), tmp + '0');
            num /= 10;
        }

        return res;
    }

    string helper(string num1, int len1, string num2, int len2) {
        string res;
        int carry, sum1, sum = 0;
        int f1, f2, t;
        int i, j;

        //cout << num1 << " " << num2 << endl;

        /* 模拟竖式乘法 */
        f2 = 1;
        for (i = len2 - 1; i >= 0; i--) {
            sum1 = 0;
            carry = 0;
            f1 = 1;
            for (j = len1 - 1; j >= 0; j--) {
                t = multi(num2[i], num1[j], carry);
                t *= f1;
                f1 *= 10;
                sum1 += t;
            }
            cout << sum1 << " " << f2 << " " << carry << endl;
            if (carry)
                sum1 += f1 * carry;
            sum1 *= f2;
            f2 *= 10;

            cout << sum << " - " << sum1 << endl;
            sum += sum1;
            cout << sum << " -- " << sum1 << endl;
        }

        return convert(sum);
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        string res;
        int len1 = num1.length(), len2 = num2.length();

        /* 长的作为被乘数，短的作为乘数 */
        if (len1 < len2) {
            res = helper(num2, len2, num1, len1);
        } else {
            res = helper(num1, len1, num2, len2);
        }

        return res;
    }
};
