
/* 位运算 */
class Solution {
public:
    string toHex(int num) {
        string ans;
        string hex = "0123456789abcdef";

        if (num == 0)
            return "0";

        while (num && ans.size() < 8) {
            ans = hex[num & 0xf] + ans;
            num >>= 4;
        }

        return ans;
    }
};

/* 错误 - 没考虑负数情况 */
class Solution {
public:
    string helper(int num) {
        string ans;
        cout << num << endl;

        if (num < 10)
            ans = num + '0';
        else if (num < 16)
            ans = num - 10 + 'a';

        return ans;
    }

    string toHex(int num) {
        string ans;
        int M = 16;

        if (num == 0)
            return "0";

        while (num > 0) {
            int t = num % M;
            ans.insert(0, helper(t));
            num /= 16;
            cout << "tohex " << num << endl;
        }

        return ans;
    }
};
