
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
            //cout << x << " " << x << " " << carry << " " << res << endl;
            ans.insert(ans.begin(), res % 10 + '0');
            carry = res / 10;
            i--;
            j--;
        }

        return ans;
    }
};


class Solution {
public:

    char add(char a, char b, int &c) {
        int ai = a - '0';
        int bi = b - '0';
        int resi;

        resi = ai + bi + c;
        if (resi >= 10) {
            resi -= 10;
            c = 1;
        } else {
            c = 0;
        }

        //cout << c << " " << (char) (resi + '0') << endl;

        return resi + '0';
    }

    string addStrings(string num1, string num2) {
        string res;
        int len1 = num1.length(), len2 = num2.length();
        int carry = 0;
        int i = len1 - 1, j = len2 - 1, k = 0;

        if (len1 == 0)
            return num2;
        if (len2 == 0)
            return num1;

        /* 先预留进位空间 */
        res.assign(max(len1, len2) + 1, '0');
        while (i >= 0 && j >= 0) {
            res[res.size() - k - 1] = add(num1[i], num2[j], carry);
            i--;
            j--;
            k++;
        }

        if (len1 > len2) {
            while (i >= 0) {
                res[res.size() - k - 1] = add(num1[i], '0', carry);
                i--;
                k++;
            }
        } else if (len1 < len2) {
            while (j >= 0) {
                res[res.size() - k - 1] = add('0', num2[j], carry);
                j--;
                k++;
            }
        }

        /* 检查是否有进位 */
        if (carry == 1)
            res[0] = '1';
        else
            res.erase(0, 1);

        return res;
    }
};
