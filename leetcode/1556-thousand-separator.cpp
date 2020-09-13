

class Solution {
public:
    string thousandSeparator(int n) {
        string res;
        int cnt = 0;

        if (n == 0)
            res.push_back(0 + '0');

        while (n > 0) {
            int num = n % 10;
            res.insert(res.begin(), num + '0');
            cnt++;
            n /= 10;
            if (cnt == 3 && n != 0) {
                res.insert(res.begin(), '.');
                cnt = 0;
            }
        }

        return res;
    }
};
